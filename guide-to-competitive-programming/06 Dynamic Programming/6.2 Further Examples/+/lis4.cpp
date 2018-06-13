
#include <bits/stdc++.h>

using namespace std;

//O(N LOG N)
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

int main(){

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve4(a, n) << endl;

    return 0;
}