#include <bits/stdc++.h>

using namespace std;

//O(K * N) donde K = LIS
//complejidad espacial: O(K)
int solve(int *a, int n){
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

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve(a, n) << endl;

    return 0;
}
