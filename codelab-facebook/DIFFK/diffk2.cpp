#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)
// Space Complexity O(1)

int diffPossible(vector<int> &A, int B) {
    int i = 0;
    int j = 1;
    while(i < A.size() && j < A.size()){
        if(i == j) j++;
        if(A[j]-A[i] < B) j++;
        else if(A[j] - A[i] > B) i++;
        else return 1;
    }
    return 0;
}


int main(){


    return 0;
}