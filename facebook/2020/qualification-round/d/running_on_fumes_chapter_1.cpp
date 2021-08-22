#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    vector<ll> ans(n);
    vector<ll> left(n);

    for(int i=0; i<n; ++i) cin >> c[i];
    ll cur_left = m;
    bool empty = false;
    bool impossible = false;
    for(int i=0; i<n; ++i){
      if(!empty){
        left[i] = cur_left;
        if(i>0) ans[i] = ans[i-1];
        if(cur_left == 0) empty = true;
        else cur_left--;
      }else{
        ll cost = LONG_LONG_MAX;
        for(int j=i-1; j>=max(0,i-m); --j){
          if(c[j]==0) continue;
          if(c[j]+ans[j] < cost){
            cost = c[j]+ans[j];
            cur_left = m-(i-j);
          }
        }
        if(cost == LONG_LONG_MAX){
          impossible = true;
          break;
        }
        ans[i] = cost;
        left[i] = cur_left;
        empty = cur_left == 0 ? true : false;
        if(cur_left > 0) cur_left--;
      }
    }
    cout << "Case #" << k+1 << ": ";
    if(impossible)
      cout << -1;
    else
      cout << ans[n-1];
    cout << endl;
  }
  return 0;
}
