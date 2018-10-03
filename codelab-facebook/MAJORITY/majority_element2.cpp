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

int majorityElement2(vector<int> &num) {
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < num.size(); i++) {
        num[majorityIndex] == num[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    return num[majorityIndex];
}

int main(){


    return 0;
}