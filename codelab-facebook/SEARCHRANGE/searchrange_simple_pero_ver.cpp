#include <bits/stdc++.h>

using namespace std;

//Ver si se puede mejorar
//Your solution is not well optimized for runtime. Focus your effort in solving the problem in shorter time frame.
//Your submission timed out for the following input:
//34 1 1 2 2 2 2 3 3 3 3 3 3 3 4 4 5 5 5 5 5 6 6 6 7 7 8 8 8 8 9 9 10 10 10 
//1

//n = 34
//vector = 1 1 2 2 2 2 3 3 3 3 3 3 3 4 4 5 5 5 5 5 6 6 6 7 7 8 8 8 8 9 9 10 10 10 
//target = 1

int searchLeftSide(const vector<int> &A, int B, int l, int r){
    if(l == r){
        if(A[l] == B) return l;
        else return -1;
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B <= midElement){
        return searchLeftSide(A, B, l, mid);
    }else{
        return searchLeftSide(A, B, mid+1, r);
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
    }else{
        return searchRightSide(A, B, mid, r);
    }
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int left = searchLeftSide(A, B, 0, A.size());
    int right = searchRightSide(A, B, 0, A.size());
    return {left, right};
}

int main(){


    return 0;
}