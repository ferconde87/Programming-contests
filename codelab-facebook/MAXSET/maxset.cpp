#include <bits/stdc++.h>

using namespace std;

vector<int> maxset(vector<int> &A) {
    long long maxValue = LONG_MIN;
    long long curValue = 0;
    vector<int> result;
    vector<int> cur;
    for(int e : A){
        if(e < 0){
            if(curValue > maxValue){
                maxValue = curValue;
                result = cur;
            }
            curValue = 0;
            cur.clear();
        }else{
            cur.push_back(e);
            curValue += e;
        }
    }
    
    if(curValue > maxValue){
        return cur;
    }
    
    return result;
}

int main(){


    return 0;
}