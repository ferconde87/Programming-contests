#include <bits/stdc++.h>

using namespace std;

int trailingZeros(int A) {
    int count = 0; 
    for (int i = 5; i <= A; i *= 5) 
        count += A / i; 
    return count;
}


int main(){


    return 0;
}