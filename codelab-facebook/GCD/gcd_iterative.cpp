#include <bits/stdc++.h>

using namespace std;

int gcd(int A, int B){
    if(A < B) swap(A, B);
    while(B != 0){
        A = (A % B);
        if(A < B) swap(A, B);
    }
    return A;
}

int main(){

    assert(gcd(9,6)==3);
    assert(gcd(7,5)==1);
    assert(gcd(3,0)==3);

    return 0;
}