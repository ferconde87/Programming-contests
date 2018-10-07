#include <bits/stdc++.h>

using namespace std;

// Wrong Answer => hay que explorar ambas opciones cuando c == A[i] == B[j]
// int isInterleave(string A, string B, string C) {
//     int n = A.size();
//     int m = B.size();
//     if(C.size() != (A.size() + B.size())) return 0;
//     int i = 0, j = 0;
//     for(char c : C){
//         if(i < n && c == A[i]) i++;
//         else if(j < m && c == B[j]) j++;
//         else return 0;
//     }
//     return 1;
// }

int isInterleaveRec(string A, int i, int n, string B, int j, int m, string C, int k, int z){
    if(k == z && i == n && j == m) return 1;
    int resultA = 0, resultB = 0;
    if(A[i] == C[k]) resultA = isInterleaveRec(A, i+1, n, B, j, m, C, k+1, z);
    if(B[j] == C[k]) resultB = isInterleaveRec(A, i, n, B, j+1, m, C, k+1, z);
    return resultA || resultB;
}

int isInterleave(string A, string B, string C) {
    return isInterleaveRec(A, 0, A.size(), B, 0, B.size(), C, 0, C.size());
}


int main(){


    return 0;
}