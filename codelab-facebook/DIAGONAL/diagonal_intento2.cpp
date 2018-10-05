#include <bits/stdc++.h>

using namespace std;

//A matrix NxN

//Time Complexity: O(N^2) //linear in amount of elements 

//Space Complexity O(N^2)


vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > result;
    for(int j = 0; j < n; j++){
        int x = 0;
        int y = j;
        vector<int> cur;
        while(y >= 0){
            cur.push_back(A[x][y]);
            x++;
            y--;
        }
        result.push_back(cur);
    }
    for(int i = 1; i < n; i++){
        int x = i;
        int y = n-1;
        vector<int> cur;
        while(x < n){
            cur.push_back(A[x][y]);
            x++;
            y--;
        }
        result.push_back(cur);
    }
    return result;
}

int main(){


    return 0;
}