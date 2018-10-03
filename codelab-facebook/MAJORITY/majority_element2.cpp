#include <bits/stdc++.h>

using namespace std;

//Time complexity: O(N)
//Space complexity: O(1)

int majorityElement(const vector<int> &A) {
    int n = A.size();
    int candidate = A[0];
    int count = 0;
    for(int i = 0; i < A.size(); ++i){
        if(candidate == A[i]){
            count++;
        }else{
            count--;
            if(count == 0){
                candidate = A[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int main(){


    return 0;
}