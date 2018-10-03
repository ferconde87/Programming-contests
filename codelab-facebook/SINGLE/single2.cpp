#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

int singleNumber(const vector<int> &A) {
    int single = A[0];
    for(int i = 1; i < A.size(); ++i){
        single ^= A[i]; 
    }
    return single;
}



int main(){

    return 0;
}
