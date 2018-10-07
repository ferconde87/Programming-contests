#include <bits/stdc++.h>

using namespace std;

unsigned int swapBits(unsigned int x, unsigned int i, unsigned int j) {
    unsigned int lo = ((x >> i) & 1);
    unsigned int hi = ((x >> j) & 1);
    if (lo ^ hi) {
        x ^= ((1U << i) | (1U << j));
    }
    return x;
}

unsigned int reverse(unsigned int x) {
    unsigned int n = sizeof(x) * 8;
    for (unsigned int i = 0; i < n/2; i++) {
        x = swapBits(x, i, n-i-1);
    }
    return x;
}

int main(){


    return 0;
}