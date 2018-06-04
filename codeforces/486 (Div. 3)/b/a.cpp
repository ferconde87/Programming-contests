#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

bool lessSize(string s, string t) { return s.size() < t.size(); }

int main(){
    int n; cin >> n;
    string xs[n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        xs[i] = s;
    } 

    sort(xs, xs+n, lessSize);

    bool possible = true;
    for(int i = n-1; i >= 1; i--){
        if((xs[i].find(xs[i-1]))==string::npos){
           possible = false;break;
           cout << xs[i-1] << " is NOT a substring of " << xs[i] << endl;
        }
    }
    if(possible){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << xs[i] << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}