#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

int lengthOfLastWord(const string &A) {
    int result = 0;
    for(int i = A.size()-1; i >= 0; --i){
        if(A[i] == ' '){
            if(result > 0){
                break;
            }
        }else{
            result++;
        }
    }
    return result;
}


int main(){

    return 0;
}
