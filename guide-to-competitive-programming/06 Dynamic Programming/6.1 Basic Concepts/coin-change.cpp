#include <bits/stdc++.h>

using namespace std;


//Hello DP-World 
// int x;//change we have to give
// int n;//#coins
// int coins[n];//array of coins
//without restrictions in the amount of coins per value
//ie, we've unlimited amount of coins
int solve(int x, int n, int *coins){
    int dp[x+1];//dp[i] = min amount of coins needed in order to give 'i' change
    dp[0] = 0;
    for(int k = 1; k <= x; k++){
        dp[k] = INT_MAX;
        for(int i = 0; i < n; i++){
            int cur = coins[i];
            if(cur > k) continue;
            dp[k] = min(dp[k-cur]+1, dp[k]);
        }
    }
    return dp[x];
}

int main(){
    int coins[3] = {1,3,4};
    cout << solve(6, 3, coins) << endl;//2
    cout << solve(10, 3, coins) << endl;//3
    return 0;
}