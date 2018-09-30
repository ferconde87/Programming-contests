#include <bits/stdc++.h>

using namespace std;


unsigned int numSetBits(unsigned int x) {
    unsigned int total_ones = 0;
    while (x != 0) {
        x = x & (x-1);
        total_ones++;
    }
    return total_ones;
}


int main(){

    int x = 11; //00000000000000000000000000001011

    assert(numSetBits(x)==3);

    return 0;
}