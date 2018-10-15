#include <bits/stdc++.h>

using namespace std;

bool isStepnum(int x){
    string s = to_string(x);
    for(int i = 0; i < s.size() - 1; i++){
        if(!(s[i] == s[i+1]+1 || s[i] == s[i+1]-1)){
            return false;
        }
    }
    return true;
}

vector<int> stepnum(int A, int B) {
    if(B < A) return vector<int>();
    
    vector<int> result;
    for(int i = A; i <= B; i++){
        if(isStepnum(i)){
            result.push_back(i);
        }
    }

    return result;    
}

int main(){

    vector<int> result = stepnum(100, 2000);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}