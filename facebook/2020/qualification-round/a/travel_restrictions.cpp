#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("travel_restrictions_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n;
    cin >> n;
    string in = "";
    string out = "";
    cin.ignore();
    getline(cin, in);
    getline(cin, out);
    vector<vector<char> > ans(n,vector<char>(n));

    for(int i=0; i<n; ++i){
      ans[i][i]='Y';
      int j=i+1;
      while(j<n && out[j-1]=='Y' && in[j]=='Y'){
        ans[i][j]='Y';
        ++j;
      }
      while(j<n){
        ans[i][j]='N';
        ++j;
      }
      j=i-1;
      while(j>=0 && out[j+1]=='Y' && in[j]=='Y'){
        ans[i][j]='Y';
        --j;
      }
      while(j>=0){
        ans[i][j]='N';
        --j;
      }
    }

    cout << "Case #" << k+1 << ":\n";
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j)
        cout << ans[i][j];
      cout << endl;
    }
  }
  return 0;
}
