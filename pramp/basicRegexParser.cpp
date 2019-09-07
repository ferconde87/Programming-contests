
#include <iostream>
#include <string>

using namespace std;

bool isMatch(const string &text, int t_index, const string & pattern, int p_index){
  if(t_index == text.size()){
    if(p_index == pattern.size()){
      return true;
    }
    if(p_index + 1 < pattern.size() && pattern[p_index + 1] == '*'){
      return isMatch(text,t_index,pattern,p_index+2);
    }else{
      return false;
    }
  }
  if(p_index == pattern.size()){
    return false;
  }
  char c = text[t_index];
  char d = pattern[p_index];
  if(c == d){
    bool useOK = isMatch(text, t_index+1, pattern, p_index+1);
    if(!useOK && (p_index+1 < pattern.size()) && pattern[p_index+1] == '*'){
      return isMatch(text, t_index, pattern, p_index+2) || isMatch(text, t_index+1, pattern, p_index);
    }
    return useOK;
  }
  if(d == '.'){
    bool useOK = isMatch(text, t_index+1, pattern, p_index+1);
    if(!useOK && p_index+1 < pattern.size() && pattern[p_index+1] == '*'){
      return isMatch(text, t_index, pattern, p_index+2) || isMatch(text, t_index+1, pattern, p_index);
    }
    return useOK;
  }
  if(p_index + 1 < pattern.size() && pattern[p_index+1] == '*'){
    return isMatch(text, t_index, pattern, p_index+2);
  }
  return false;
}


bool isMatch( const string &text, const string &pattern ) 
{
  return isMatch(text, 0, pattern, 0);
}

int main() {
  cout << isMatch("aa","aaa*") << endl;
  cout << isMatch("aaa","aaa*") << endl;
  cout << isMatch("aaabd","a*.c*d") << endl;
  cout << isMatch("acd", "ab*c.") << endl ;
  cout << isMatch("abcbe", ".*") << endl;
  cout << isMatch("abcbea", ".*a") << endl;
  cout << isMatch("abcbea", ".*b") << endl;//0
  return 0;
}
