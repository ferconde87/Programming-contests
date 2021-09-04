#include <bits/stdc++.h>

using namespace std;

double dist(pair<int, int> a, pair<int, int> b){
  return sqrt(pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2));
}

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> ps(n+1);
  for(int i=0; i<n; ++i){
    int x, y;
    cin >> x >> y;
    ps[i] = {x, y};
  }
  ps[n] = ps[0];
  double ans = 0;
  for(int i=0; i<n; ++i){
    ans += dist(ps[i],ps[i+1]);
  }
  cout << "Perimter = " << ans << endl;
}
