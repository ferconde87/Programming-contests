#include <bits/stdc++.h>

using namespace std;

int colorful(int N) {
    string s = to_string(N);
    int len = s.size();
    
    map<long long, bool> Hash;

    for(int i = 0; i < len; ++i) {
        long long mul = 1;
        for(int j = i; j < len; ++j) {
            mul *= (long long)(s[j] - '0');
            if(Hash.find(mul) != Hash.end())
                    return 0;
            Hash[mul] = true;
        }
    }

    return 1;
}


int main(){


    return 0;
}