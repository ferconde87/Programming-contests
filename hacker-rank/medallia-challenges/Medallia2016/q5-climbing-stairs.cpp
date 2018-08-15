#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

vector<int> memo;

int waysToClimb(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(memo[n] == -1){
        memo[n] = waysToClimb(n-1) + waysToClimb(n-2);
    }
    return memo[n];
}

int main(){
    int t; cin >> t;//test cases
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        memo.resize(n+1, -1);
        cout << waysToClimb(n) << endl;
    }
    return 0;
}