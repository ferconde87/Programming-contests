#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

vector<int> wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i = 0; i < n - 1; i+= 2){
        swap(A[i], A[i+1]);
    }
    return A;
}


int main(){

    return 0;
}
