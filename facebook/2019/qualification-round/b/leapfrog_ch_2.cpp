#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("leapfrog_ch_2_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    string s;
    cin.ignore();
    getline(cin, s);
    int betas = count(s.begin(), s.end(), 'B');
    int lilypads = count(s.begin(), s.end(), '.');
    cout << "Case #" << k << ": ";
    if(betas>=2 && lilypads >= 1 || (betas==1 && lilypads==1))
      cout << "Y\n";
    else
      cout << "N\n";
  }
  return 0;
}
