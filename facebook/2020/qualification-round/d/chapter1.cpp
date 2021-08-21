#include <bits/stdc++.h>

using namespace std;

int main(){
  // freopen("chapter1_input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    vector<int> ans(n);
    vector<int> left(n);

    for(int i=0; i<n; ++i) cin >> c[i];
    unsigned int cur_left = m;
    for(int i=0; i<n; ++i){
      if(cur_left > 0){
        left[i] = cur_left;
        cur_left--;
        continue;
      }
      unsigned int cost = UINT_MAX;
      for(int j=i-1; j>=max(0,i-m); --j){
        if(c[j]==0) continue;
        if(c[j]+ans[j] < cost){
          cost = c[j]+ans[j];
          cur_left = m-(i-j);
        }
      }
      ans[i] = cost;
      left[i] = cur_left;
    }
    cout << "Case #" << k+1 << ": " << ans[n-1] << endl;
  }
  return 0;
}
