#include <bits/stdc++.h>

using namespace std;

// https://oeis.org/wiki/Euler%E2%80%93Mascheroni_constant
// 0.57721566490153286060651209008240243104215933593992

// Test case 1 OK
// Test case 2 OK
// Test case 3 OK

#define ld long double
#define ll long long
const int MAX = 1e6;
double dp[MAX];

int main(){
  // Stirling numbers of first kind
  for (int i=1; i<MAX; i++)
    dp[i] = dp[i-1]+1.0/i;

  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    ll n; cin >> n;
    if(n < MAX){
      cout << "Case #" << k << ": " << setprecision(10) << dp[n] << endl;
    } else {
      cout << "Case #" << k << ": " << setprecision(10) << 0.57721566490153286060651209008240243104215933593992 + log(n) << endl;
    }
  }
}
