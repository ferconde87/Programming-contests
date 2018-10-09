#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    while(A.size() > 0 && *A.begin() == 0) A.erase(A.begin());
    if(A.size() == 0) return {1};
    for(int i = A.size() - 1; i >= 0; i--){
        A[i]++;
        if(A[i] < 10) break;
        A[i] = 0;
    }
    if(A.front() == 0){
        A.insert(A.begin(), 1);
    }
    return A;
}

int main(){

    return 0;
}