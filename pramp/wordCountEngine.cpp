#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <map>
#include <set>
#include <utility>


using namespace std;

string stripOutPunctuation(const string & document){
  string answer = document;
  string puntuations = "'!?.,:;";
  for(char p : puntuations){
    answer.erase(remove(answer.begin(),answer.end(), p),answer.end());
  }
  return answer;
}

vector<string> splitBySpace(string ws){
  istringstream iss(ws);
  vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};
  return words;
}

string toLower(string & w){
  string answer;
  for(char c : w){
    answer.push_back(tolower(c));
  }
  return answer;
}

void convertToLower(vector<string> & vs){
 for(int i = 0; i < vs.size(); ++i){
   vs[i] = toLower(vs[i]);
 }
}

vector<vector<string>> wordCountEngine( const string& document ) {
  string words = stripOutPunctuation(document);
  vector<string> ws = splitBySpace(words);
  convertToLower(ws);
  unordered_map<string, int> unordered_occurrences;
  //save words and occurrences 
  for(auto w : ws){
    auto it = unordered_occurrences.find(w);
    if(it != unordered_occurrences.end()){
      it->second++;
    }else{
      unordered_occurrences.insert(make_pair(w,1));
    }
  }
  //save first by occurrences second by order in original sentence
  map<int,vector<string> > occurrences;
  set<string> considered;
  for(auto w : ws){
    auto it = considered.find(w);
    if(it == considered.end()){
      int amount = unordered_occurrences[w];
      auto itAmount = occurrences.find(amount);
      if(itAmount == occurrences.end()){
        vector<string> xs;
        xs.push_back(w);
        occurrences.insert(make_pair(amount,xs));
      }else{
        itAmount->second.push_back(w);
      }
      considered.insert(w);
    }
  }
  //return the answer
  vector<vector<string> > answer;
  for(auto it = occurrences.rbegin(); it != occurrences.rend(); ++it){
    string amount_in_letters = to_string(it->first);
    for(auto itw : it->second){
      vector<string> v;
      v.push_back(itw);
      v.push_back(amount_in_letters);
      answer.push_back(v);
    }
  }
  return answer;
}

int main() {
  return 0;
}

