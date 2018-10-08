#include <bits/stdc++.h>

using namespace std;

int reverse(int A) {
    string s = to_string(A);
    int offset = (s.front() == '-') ? 1 : 0;
    reverse(s.begin()+offset, s.end());
    long long num = stoll(s);
    if(num > INT_MAX || num < INT_MIN) return 0;
    return (int)num;
}

int main(){


    return 0;
}