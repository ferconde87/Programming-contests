#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

    unsigned int n, k;
    cin >> n >> k;
    bitset<101> bs;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
      int x; cin >> x;
      if(bs[x]) continue;
      bs.set(x);
      ans.push_back(i); 
    }
    if(ans.size()<k) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(auto e : ans) cout << e << " ";
    } 

    return 0;
}