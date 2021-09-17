#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("weak_typing_chapter_1_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    int ans = 0;
    char last = 'F';
    for(int i=0; i<n; ++i){
      if(s[i] != 'F' && s[i] != last){
        ++ans;
        last = s[i];
      }
    }
    if(ans) --ans;
    cout << "Case #" << k << ": " << ans << endl;
  }
  return 0;
}
