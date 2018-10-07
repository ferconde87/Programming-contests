#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > generate(int A) {
    if(A == 0) return {};
    vector<vector<int> > result({{1}});
    for(int i = 1; i < A; i++){
        vector<int> row({1});
        for(int j = 1; j < i; j++){
            row.push_back(result[i-1][j] + result[i-1][j-1]);
        }
        row.push_back(1);
        result.push_back(row);
    }
    return result;
}

int main(){


    return 0;
}