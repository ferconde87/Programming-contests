#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(N)

// Space Complexity: O(1)

int bulbs(vector<int> &A) {
    int result = 0;
    for(int i = 0; i < A.size(); ++i){
        if(A[i] == 1) continue;
        result++;
        A[i] = 1;
        for(int j = i+1; j < A.size(); j++){
            A[j] = (A[j] == 1) ? 0 : 1;
        }
    }
    return result;
}
int main(){



    return 0;
}