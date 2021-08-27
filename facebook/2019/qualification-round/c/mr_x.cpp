#include <bits/stdc++.h>

using namespace std;

// TODO: parser and eval or implementing shunting-yard algorithm or something else
// https://en.wikipedia.org/wiki/Shunting-yard_algorithm

int main(){
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    cin.ignore();
    string s;
    getline(cin, s);
    bool op_ok = true;
    queue<char> q;
    for(char c : s){
      if(c == '(') q.push(c);
      else if(c == ')'){
        if(q.empty()){
          op_ok = false;
          break;
        }else{
          q.pop();
        }
      } else if(c == 'x' || c == 'X' || c == '1' || c == '0') {
        op_ok = true;
      } else {
        op_ok = false;
      }
    }
    cout << "Case #" << k << ": " << (int)op_ok << endl;
  }
  return 0;
}
