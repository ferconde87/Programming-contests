#include <bits/stdc++.h>

using namespace std;

unsigned int reverse(unsigned int A) {
    int answer = 0;
    for(int i = 0; i < 32; i++){
        if((A & (1 << i)) != 0)
            answer |= (1 << 31-i);
    }
    return answer;
}

int main(){


    return 0;
}