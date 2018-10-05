#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > result;
    for(int j = 0; j < n; j++){
        vector<int> cur;
        for(int x = 0, y = j; y >= 0; x++, y--)
            cur.push_back(A[x][y]);
        result.push_back(cur);
    }
    for(int i = 1; i < n; i++){
        vector<int> cur;
        for(int x = i, y = n-1; x < n; x++, y--)
            cur.push_back(A[x][y]);
        result.push_back(cur);
    }
    return result;
}

int main(){



    return 0;
}