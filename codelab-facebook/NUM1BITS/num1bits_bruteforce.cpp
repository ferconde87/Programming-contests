#include <bits/stdc++.h>

using namespace std;


int numSetBits(unsigned int A) {
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(A & (1 << i)) ans++;
    }
    return ans;
}


int main(){

    int x = 11; //00000000000000000000000000001011

    assert(numSetBits(x)==3);

    return 0;
}