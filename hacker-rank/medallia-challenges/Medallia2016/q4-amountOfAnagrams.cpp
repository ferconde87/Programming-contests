#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


//one delimeter
template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if(!item.empty()) *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

//multiple delimeters
vector<string> split(const string &input, string delimiters){
    vector<string> result;
    size_t from = 0;
    size_t to = 0;
    while(to != string::npos){
        to = input.find_first_of(delimiters, from);
        string cur = input.substr(from, to - from);
        if(!cur.empty()) result.push_back(cur);
        from = to+1;
    }
    return result;
}

vector<int> getOccurrences(string word){
    vector<int> counter(26);
    for(char c : word){
        counter[c - 'a']++;
    }
    return counter;
}

//assuming word & phrase only use lowercase characters
int amountOfAnagrams(string word, vector<string> phrase){
    vector<int> occurrences = getOccurrences(word);
    int amount = 0;
    for(string current : phrase){
        vector<int> current_occurrences = getOccurrences(current);
        if(occurrences == current_occurrences){
            amount++;
        }
    }
    return amount;
}

int main(){
    string word; getline(cin, word);
    int n; cin >> n; cin.ignore();
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        vector<string> phrase = split(line, " ,.");
        cout << amountOfAnagrams(word, phrase) << endl;
    }
        return 0;
}