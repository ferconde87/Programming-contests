#include <bits/stdc++.h>

using namespace std;

// 1) num % 10 gives you the last digit of a number.
// 2) num / 10 gives you the number after removing the last digit.
// 3) num * 10 + digit appends the digit at the end of the number.

int reverse(int A) {
    long long num = 0;
    int sign = (A < 0) ? -1 : 1;
    if(A < 0) A *= -1;
    while(A > 0){
        int digit = A % 10;
        A /= 10;
        num = num * 10 + digit;
    }
    if(num > INT_MAX) return 0;
    return num*sign;
}

int main(){


    return 0;
}