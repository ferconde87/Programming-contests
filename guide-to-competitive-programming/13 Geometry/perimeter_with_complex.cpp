#include <bits/stdc++.h>

using namespace std;

typedef long double C;
typedef complex<C> P; //Point

#define X real()
#define Y imag()

int main(){
  int n;
  cin >> n;
  vector<P> ps(n+1);
  for(int i=0; i<n; ++i){
    C x, y;
    cin >> x >> y;
    ps[i] = {x, y};
  }
  ps[n] = ps[0];
  double ans = 0;
  for(int i=0; i<n; ++i){
    ans += abs(ps[i]-ps[i+1]);
  }
  cout << "Perimter = " << ans << endl;

}
