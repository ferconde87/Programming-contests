#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    while(A.size() > 0 && *A.begin() == 0) A.erase(A.begin());
    if(A.size() == 0) return {1};
    int lastIndex = A.size() - 1;
    A[lastIndex]++;
    int carry = 0;
    if(A[lastIndex] == 10){
        carry = 1;
        A[lastIndex] = 0;
    }
    if(carry > 0){
        for(int i = lastIndex - 1; i >= 0; i--){
            A[i]++;
            carry = 0;
            if(A[i] < 10) break;
            A[i] = 0;
            carry = 1;
        }
        if(carry){
            A.insert(A.begin(), 1);
        }
    }
    return A;
}

int main(){

    return 0;
}