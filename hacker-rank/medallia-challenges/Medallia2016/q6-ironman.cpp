#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int ironMan(const vector<int> & battles){
    int min_power = INT_MAX;
    int n = battles.size();
    int current = 0;
    for(int i = 0; i < n; i++){
        current += battles[i];
        min_power = min(min_power, current);
    }
    if(min_power >= 1) return 1;
    return abs(min_power) + 1;
}

int main(){
    int t; cin >> t;//test cases
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> battles(n);
        for(int i = 0; i < n; i++) cin >> battles[i];
        cout << ironMan(battles) << endl;
    }
    return 0;
}