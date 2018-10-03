#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

int lengthOfLastWord(const string &A) {
    int result = 0;
    int cur = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == ' '){
            if(cur > 0){
                result = cur;
                cur = 0;
            }
        }else{
            cur++;
        }
    }
    if(cur > 0) result = cur;
    
    return result;
}



int main(){

    return 0;
}
