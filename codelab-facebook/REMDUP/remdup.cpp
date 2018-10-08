#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &A) {
    int j = 0;
    for(int i = 0; i < A.size(); i++){
        if(i < A.size() - 1 && A[i]==A[i+1]) continue;
        A[j++] = A[i];
    }
    return j;
}

int removeDuplicates2(vector<int> &A) {
    int j = 0;
    for(int i = 0; i < A.size() - 1; i++){
        if(A[i]==A[i+1]) continue;
        A[j++] = A[i];
    }
    A[j++] = A.back();
    return j;
}

int main(){


    return 0;
}