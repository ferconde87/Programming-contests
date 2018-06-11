#include <bits/stdc++.h>

using namespace std;

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

//O(N log N) but WA 9 on http://www.spoj.com/problems/ELIS/
int  solve_n_log_n(int *a, int n){ 
    multiset < int > s;
    multiset < int > :: iterator it;

    for(int i = 0; i < n; i++){
        s.insert(a[i]);
        
        it = s.upper_bound(a[i]);
        
        if(it != s.end())
            s.erase(it);
    }

    return s.size();
}


int main(){

    cout << solve(a, 8) << endl;
    cout << solve_n_log_n(a, 8) << endl;

    int b[7] = {3, 1, 2, 0, 5, 4, 10};
    cout << solve(b,7) << endl;
    cout << solve_n_log_n(b,7) << endl;

    int c[5] = {1, 4, 2, 4, 3};
    cout << solve(c, 5) << endl;
    cout << solve_n_log_n(c, 5) << endl;

    return 0;
}