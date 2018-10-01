#include <bits/stdc++.h>

using namespace std;

int gcd(int A, int B){
    int min_elem = min(A,B);
    if(min_elem == 0) return max(A,B);
    for(int x = min_elem; x >= 2; --x){
        if((A%x)==0 && (B%x==0)){
            return x;
        }
    }
    return 1;
}

int main(){

    assert(gcd(6,9) == 3);

    return 0;
}