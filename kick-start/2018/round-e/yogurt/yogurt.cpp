#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  int t;
  cin >> t;
  for(int c=1; c<=t; ++c){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int days=0;
    int left=k;
    int ans=0;
    for(int i=0; i<n; ++i){
      if(!left){
        ++days;
        left=k;
      }
      if(v[i]-days > 0){
        ++ans;
        --left;
      }
    }
    cout << "Case #" << c << ": " << ans << endl;
  }
  return 0;
}
