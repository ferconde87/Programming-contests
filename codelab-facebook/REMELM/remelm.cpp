#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)

// Space Complexity O(1)

int removeElement(vector<int> &A, int B) {
    int j = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == B) continue;
        swap(A[i], A[j++]);
    }
    return j;
}

int main(){


    return 0;
}