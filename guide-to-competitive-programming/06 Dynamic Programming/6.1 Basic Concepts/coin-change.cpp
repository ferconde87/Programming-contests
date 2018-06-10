#include <bits/stdc++.h>

using namespace std;


//Hello DP-World 
// int x;//change we have to give
// int n;//#coins
// int coins[n];//array of coins
//without restrictions in the amount of coins per value
//ie, we've unlimited amount of coins

int iterative(int x, int n, int *coins){
    int value[x+1];//value[i] = min amount of coins needed in order to give 'i' change
    value[0] = 0;
    for(int k = 1; k <= x; k++){
        value[k] = INT_MAX;
        for(int i = 0; i < n; i++){
            int cur = coins[i];
            if(cur > k) continue;
            value[k] = min(value[k-cur]+1, value[k]);
        }
    }
    return value[x];
}

int coins[3] = {1,3,4};
int bruteForceRecursive(int x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    int best = INT_MAX;
    for (auto c : coins) {
        if(c > x) continue;
        best = min(best, bruteForceRecursive(x-c)+1);
    }
    return best;
}

unsigned int bruteForceRecursive2(int x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    unsigned int best = INT_MAX;
    for (auto c : coins) {
        best = min(best, bruteForceRecursive2(x-c)+1);
    }
    return best;
}

unordered_map<int, int> dp;
int counter = 0;
int dpTopDown(int x, int n, int *coins, int cost){
    for(int i = n-1; i >= 0; i--){
        int rem = x-coins[i];
        if(rem < 0) continue;
        int curBest = INT_MAX;
        if(dp.find(rem) != dp.end()) curBest = dp[rem];
        if(curBest <= cost+1) continue;
        dp[rem] = cost+1;
        dpTopDown(rem, n, coins, cost+1);
    }
    return dp[0];
}

//From the guide
int const N = 10000;
int value[N];
int ready[N];
int solve(int x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INT_MAX;
    for (auto c : coins) {
        if(c > x) continue;
        best = min(best, solve(x-c)+1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

int solveIterative(int k){
    value[0] = 0;
    for (int x = 1; x <= k; x++) {
        value[x] = INT_MAX;
        for (auto c : coins) {
            if (x-c >= 0) {
                value[x] = min(value[x], value[x-c]+1);
            }
        }
    }
    return value[k];
}


void contructingASolution(int k){
    int first[N];
    value[0] = 0;
    for (int x = 1; x <= k; x++) {
        value[x] = INT_MAX;
        for (auto c : coins) {
            if (x-c >= 0 && value[x-c]+1 < value[x]) {
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }

    while(k > 0){
        int coin = first[k];
        cout << coin << " ";
        k-= coin;
    }
    cout << "\n";
}

int main(){
    int coins[3] = {1,3,4};
    cout << iterative(6, 3, coins) << endl;//2
    cout << iterative(10, 3, coins) << endl;//3

    cout << dpTopDown(10, 3, coins, 0) << endl;

    cout << bruteForceRecursive(10) << endl;
    cout << bruteForceRecursive2(10) << endl;

    cout << solve(10) << endl;
    cout << solveIterative(10) << "\n\n";
    contructingASolution(10);

    return 0;
}