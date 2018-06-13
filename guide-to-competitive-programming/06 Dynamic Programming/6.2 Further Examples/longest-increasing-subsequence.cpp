#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int a[8] = {6,2,5,1,7,4,8,3};

//Let length(k) denote the length of the longest increasing
// subsequence that ends at position k
//O(n^2) CA http://www.spoj.com/problems/ELIS/
int length[10000];
int solve(int *a, int n){
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (a[i] < a[k]) {
                length[k] = max(length[k],length[i]+1);
            }
        }
    }

    return *max_element(length, length+n);
}

//(!) Assuming Longest NON_STRICTLY increasing SECUENCY http://www.spoj.com/problems/ELIS/
int  solve_non_strict_n_log_n(int *a, int n){ 
    multiset < int > s;
    multiset < int > :: iterator it;

    for(int i = 0; i < n; i++){
        s.insert(a[i]);
        
        it = s.upper_bound(a[i]);
        
        if(it != s.end()){
            s.erase(it);
        }
    }

    return s.size();
}

int solve4(int *a, int n){
    set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(a[i])==s.end()){
            s.insert(a[i]);
            auto it = s.upper_bound(a[i]);
            if(it != s.end()) s.erase(it);
        } 
    }
    return s.size();
}



//O(K * N) donde K = LIS
//complejidad espacial: O(K)
int solve3(int *a, int n){
    if(n == 0) return 0;
    int k = *max_element(a, a+n);
    int dp[k+1];//dp_i = min_element(a) con max LIS-until-ith 
    dp[0] = INT_MIN;
    int lis = 0;// max LIS until now
    for(int i = 0; i < n; i++){
        int j = lis;
        while(a[i] <= dp[j]) j--;
        if(j+1>lis || dp[j+1]>a[i]){
            dp[j+1] = a[i];
        } 
        lis = max(lis,j+1); 
    }
    return lis;
}


int main(){
    cout << solve(a, 8) << endl;
    cout << solve_non_strict_n_log_n(a, 8) << endl;
    cout << solve3(a, 8) << endl;
    cout << solve4(a, 8) << endl;
    cout << endl;

    int b[7] = {3, 1, 2, 0, 5, 4, 10};
    cout << solve(b,7) << endl;
    cout << solve_non_strict_n_log_n(b,7) << endl;
    cout << solve3(b,7) << endl;
    cout << solve4(b,7) << endl;
    cout << endl;
    int c[5] = {1, 4, 2, 4, 3};
    cout << solve(c, 5) << endl;
    cout << solve_non_strict_n_log_n(c, 5) << endl;
    cout << solve3(c, 5) << endl;
    cout << solve4(c, 5) << endl;
    cout << endl;
    int d[13] = {3, 2, 5, 7, 1, 8, 6, 7, 8, 2, 6, 9, 6};
    cout << solve(d, 13) << endl;
    cout << solve_non_strict_n_log_n(d, 13) << endl;
    cout << solve3(d, 13) << endl;
    cout << solve4(d, 13) << endl;
    cout << endl;

    int e[15] = {3, 2, 5, 7, 1, 8, 6, 7, 8, 2, 6, 9, 6, 6, 6};
    cout << solve(e, 15) << endl;
    cout << solve_non_strict_n_log_n(e, 15) << endl;// 7 => (!) No estrictamente creciente
    cout << solve3(e, 15) << endl;
    cout << solve4(e,15) << endl;

    return 0;
}