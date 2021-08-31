#include <bits/stdc++.h>

using namespace std;

int vowels(string &s){
  int ans=0;
  for(char c : s)
    if(c=='A'||c =='E'||c =='I'||c =='O'||c =='U')
      ans++;
  return ans;
}

int consonant(string &s){
  int ans=0;
  for(char c : s)
    if(c!='A'&&c!='E'&&c !='I'&&c!='O'&&c!='U')
      ans++;
  return ans;
}

int maxVowel(vector<int> & ls){
  vector<int> vs({ls[0],ls['E'-'A'],ls['I'-'A'],ls['O'-'A'],ls['U'-'A']});
  return *max_element(vs.begin(), vs.end());
}

int maxConstant(vector<int> &ls){
  int ans = 0;
  for(int i=1; i<26; ++i){
    if(i != ('E'-'A') && i != ('I'-'A') && i != ('O'-'A') && i != ('U'-'A')){
      ans = max(ans, ls[i]);
    }
  }
  return ans;
}

int main(){
  freopen("consistency_chapter_1_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  cin.ignore();
  for(int k=0; k<t; ++k){
    string s;
    getline(cin, s);
    int n = s.size();
    int vs = vowels(s);
    int cs = n - vs;
    vector<int> letters(26,0);
    for(char c : s){
      letters[c-'A']++;
    }
    int maxV = maxVowel(letters);
    int maxC = maxConstant(letters);
    int ans = min(2*(vs-maxV)+cs,2*(cs-maxC)+vs);
    cout << "Case #" << k+1 << ": " << ans << endl;
  }
  return 0;
}
