#include <bits/stdc++.h>

using namespace std;

string tabs(int n){
    string ans;
    for(int i = 0; i < n; i++){
        ans.append("\t");
    }
    return ans;
}

vector<string> prettyJSON(string A) {
    int ntabs = 0;
    vector<string> ans;
    int i = 0; 
    string cur;
    for(; i < A.size(); i++){
        char c = A[i];
        string ts = tabs(ntabs);
        if(c == '[' || c == '{'){
            if(!cur.empty()){
                ans.push_back(ts.append(cur));
                cur.clear();
            }
            ans.push_back(tabs(ntabs).append({c}));
            ntabs++;
        }else if(c == ']' || c == '}'){
            if(!cur.empty()){
                ans.push_back(ts.append(cur));
                cur.clear();
            }
            ntabs--;
            string close = tabs(ntabs);
            close.push_back(c);
            if(i < A.size() && A[i+1] == ','){
                close.push_back(',');
                i++;
            }
            ans.push_back(close);
        }else if(c == ':'){
            cur.push_back(c);
        }else if(c == ','){
            cur.push_back(c);
            ans.push_back(ts.append(cur));
            cur.clear();
        }else{
            cur.push_back(c);
        }
    }
    return ans;
}

int main(){


    return 0;
}