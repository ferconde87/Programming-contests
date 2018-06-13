#include <bits/stdc++.h>

using namespace std;

//O(N log N) +eficiente. Una sola operación O(log N) por iteración
int solve5(int *a, int n){
    set<int> s;
    for(int i = 0; i < n; i++){
        auto it = s.insert(a[i]);
        if(it.second && ++it.first!=s.end()) s.erase(it.first);
    }
    return s.size();
}

int main(){

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve5(a, n) << endl;

    return 0;
}