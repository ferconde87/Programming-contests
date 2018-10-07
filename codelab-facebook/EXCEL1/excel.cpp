#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string A) {
    int n = A.size();
    int result = 0;
    reverse(A.begin(), A.end());
    for(int i = 0, mul = 1; i < n; i++, mul*=26)
        result += (A[i] - 'A' + 1) * mul;
    return result;
}

int main(){


    return 0;
}