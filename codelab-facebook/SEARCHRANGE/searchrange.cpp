#include <bits/stdc++.h>

using namespace std;

int searchLeftSide(const vector<int> &A, int B, int l, int r){
    if(l == r){
        if(A[l] == B) return l;
        else return -1;
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B < midElement){
        return searchLeftSide(A, B, l, mid-1);
    }else if(B > midElement){
        return searchLeftSide(A, B, mid+1, r);
    }else{
        if((mid > 0 && B != A[mid-1]) || mid == 0)
            return mid;
        else
            return searchLeftSide(A, B, l, mid-1);
    }
}

int searchRightSide(const vector<int> &A, int B, int l, int r){
    if(l == r){
        if(A[l] == B) return l;
        else return -1;
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B < midElement){
        return searchRightSide(A, B, l, mid-1);
    }else if(B > midElement){
        return searchRightSide(A, B, mid+1, r);
    }else{
        if((mid < A.size()-1 && B != A[mid+1]) || mid == A.size()-1)
            return mid;
        else
            return searchRightSide(A, B, mid+1, r);
    }
}

vector<int> searchRange(const vector<int> &A, int B) {
    int left = searchLeftSide(A, B, 0, A.size());
    int right = searchRightSide(A, B, 0, A.size());
    return {left, right};
}

int main(){

    return 0;
}