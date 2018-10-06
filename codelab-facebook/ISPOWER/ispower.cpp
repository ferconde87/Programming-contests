#include <bits/stdc++.h>

using namespace std;

bool isPower(int A) {
    if(A == 1) return true;
    long long limitSearchSpace = sqrt(A);
    for(long long a = 2; a <= limitSearchSpace; a++){
        if(A % a == 0){
            for(long long b = a; b <= A; b *= a){
                if(b == A){
                    return true;
                } 
            }
        }
    }
    return false;
}



int main(){



}