#include <bits/stdc++.h>

using namespace std;

//O(N log N) just4fun
int solve6(int *a, int n){
    set<int> s;
    int i = 0;
    for(auto it = s.insert(a[i]); i < n; i++)
        if(it.second && ++it.first!=s.end()) s.erase(it.first);
    return s.size();
}

int main(){

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve6(a, n) << endl;

    return 0;
}