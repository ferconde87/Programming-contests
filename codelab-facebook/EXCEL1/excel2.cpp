#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string A) {
    int result = 0;
    for (int i = 0; i < A.size(); i++) {
        result = result * 26 + (A[i] - 'A' + 1);
    }
    return result;
}

int main(){


    return 0;
}