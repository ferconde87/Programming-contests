#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("traffic_control_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << "Case #" << k << ": "; 
    if(n+m-1 > a || n+m-1 > b){
      cout << "Impossible" << endl;
    }else{
      vector<vector<int> > matrix(n+1, vector<int>(m+1, 1));
      matrix[n][m] = a - (n+m-2);
      matrix[n][1] = b - (n+m-2);
      cout << "Possible" << endl;
      for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
