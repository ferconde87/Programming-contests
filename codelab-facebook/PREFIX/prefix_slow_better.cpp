#include <bits/stdc++.h>

using namespace std;

vector<string> prefix(vector<string> &A) {
    
    int n = A.size();
    vector<string> result;
    unordered_set<string> invalid_set;
    for(int i = 0; i < n; i++){
        string word = A[i];
        int len = word.size();
        string prefix;
        for(int k = 0; k < len; k++){
            char c = word[k];
            prefix.push_back(c);
            auto it = invalid_set.find(prefix);
            if(it != invalid_set.end()){
                continue;//prune
            }
            bool valid = true;
            for(int j = i+1; j < n; j++){//now j=i+1
                if(j == i) continue;
                string other = A[j];
                if(k < other.size() && c == other[k]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                result.push_back(prefix);
                break;//prefix ok! continue
            }else{
                invalid_set.insert(prefix);
            }
        }
    }
    return result;
}

int main(){


    return 0;
}