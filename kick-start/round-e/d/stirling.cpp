#include <bits/stdc++.h>

using namespace std;

// Stirling numbers of first kind

// Test case 1 OK
// Test case 2 OK
// Test case 3 TLE

#define ld long double

int main(){
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    ld n; cin >> n;
    ld ans=0;
    for(ld i=1; i<=n; ++i) ans+= 1.0/i;
    cout << "Case #" << k << ": " << setprecision(10) << ans << endl;
  }
}
