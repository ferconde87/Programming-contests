#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){
    int t; cin >> t;
    unordered_map<int, int> l;
    unordered_map<int, int> r;
    int ls = 0, rs = 0;
    for(int i = 0; i < t; i++){
        char c; cin >> c;
        int x; cin >> x;
        if(c == 'L'){
            l[x] = ls++;
        }else if(c == 'R'){
            r[x] = rs++;
        }else{
            auto it = l.find(x);
            if(it != l.end()){
                cout << min(ls-1-it->second,rs+it->second) << endl;
            }else{
                it = r.find(x);
                cout << min(rs-1-it->second, ls+it->second) << endl;
            }
        }
    }

    return 0;
}