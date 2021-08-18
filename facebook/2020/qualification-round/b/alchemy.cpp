#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("alchemy_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n;
    cin >> n;
    string in = "";
    cin.ignore();
    getline(cin, in);
    int as = count(in.begin(), in.end(), 'A');
    int bs = count(in.begin(), in.end(), 'B');
    cout << "Case #" << k+1 << ": ";
    abs(as-bs) == 1 ? (cout << "Y\n") : (cout << "N\n");  
  }
  return 0;
}
