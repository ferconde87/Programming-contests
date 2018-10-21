#include <bits/stdc++.h>

using namespace std;

//Search for the position where the element 'target' should be inserted. 
// If there are many target, return the position of the last occurrence + 1.
// (If the target isn't in the vector, return the position where it should be inserted.)

int baseCaseR(const vector<int> & A, int B, int l, int r){
    if(r >= 0 && (A[r] == B || A[r] < B)) return r+1;
    return r;
}


int searchRightPlace(const vector<int> &A, int B, int l, int r){
    if(abs(r-l) <= 1){
        return baseCaseR(A, B, l, r);
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B < midElement){
        return searchRightPlace(A, B, l, mid-1);
    }else{
        return searchRightPlace(A, B, mid, r);
    }
}

int searchRightPlace(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    return searchRightPlace(nums, target, 0, nums.size()-1);
}

int main(){

    vector<int> v = {1,2,4,8,10};

    vector<int> w = {2,3,3,3,4,5,8};

    cout << searchRightPlace(w,4) << endl;//5
    cout << searchRightPlace(v,3) << endl;//2

    return 0;
}