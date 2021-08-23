#include <bits/stdc++.h>

using namespace std;

#define ld long double

// Test case 1 OK
// Test case 2 TLE

int main(){
  int t;
  cin >> t;
  int ans;
  for(int k=1; k<=t; ++k){
    ld n;
    cin >> n;
    int ans=0;
    vector<int> v(n);
    for(int i=0; i<n; ++i) v[i]=i+1;
    ld count = 0;
    int total_cards = 0;
    do {
      ++count;
      int last = 0;
      for(int c : v) {
        if(c > last) {
          total_cards++;
          last = c;
        }
      }
    } while(next_permutation(v.begin(), v.end()));
    cout << "Case #" << k << ": " << setprecision(10) << total_cards/count << endl;
    cout << "total #" << k << ": " << setprecision(10) << total_cards << endl;
    cout << "count #" << k << ": " << setprecision(10) << count << endl;
    cout << endl;
  }
}
