#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  freopen("timber_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    // cout << t << endl;
    int n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> h(n);
    for(int i=0; i<n; ++i){
      cin >> p[i] >> h[i];
    }
    vector<array<ll, 4> > v(2*n);
    for(int i=0; i<n; ++i){
      v[2*i] = {p[i]-h[i],p[i],i,h[i]};
      v[2*i+1] = {p[i],p[i]+h[i],i,h[i]};
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(auto it=v.begin(); it!=v.end(); ++it){
      auto cur = *it;
      array<ll, 4> l = {cur[1],cur[1], 0, 0};
      auto next = upper_bound(it, v.end(), l);
      while(next != v.end() && (*next)[0] == cur[1]){
        if((*next)[2] == cur[2]) { ++next; continue; }
        ll next_h = (*next)[1] - (*next)[0];
        if((*next)[3] < cur[3]+next_h){
          (*next)[3] = cur[3]+next_h;
        }
        ++next;
      }
    }
    for(auto cur : v){
      if(cur[3] > ans)
        ans = cur[3];
    } 
    cout << "Case #" << k+1 << ": " << ans << endl;
  }


  return 0;
}
