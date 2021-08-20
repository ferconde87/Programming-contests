#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("chapter1_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(int i=0; i<n; ++i) cin >> c[i];
    int ans;

    cout << "Case #" << k+1 << ": " << ans << endl;
  }
  return 0;
}
