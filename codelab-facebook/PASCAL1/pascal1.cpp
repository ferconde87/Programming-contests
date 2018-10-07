#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > generate(int A) {
    if(A == 0) return {};
    vector<vector<int> > result;
    result.push_back({1});
    for(int i = 1; i < A; i++){
        vector<int> row;
        int lastLen = result[i-1].size();
        row.push_back(1);
        for(int j = 1; j <= i; j++){
            int cur = 0;
            if(j < lastLen) cur += result[i-1][j];
            cur += result[i-1][j-1];
            row.push_back(cur);
        }
        result.push_back(row);
    }
    return result;
}


int main(){


    return 0;
}