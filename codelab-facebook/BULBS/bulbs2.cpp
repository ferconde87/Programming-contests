#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(N)

// Space Complexity: O(1)


int bulbs(vector<int> &A) {
    int state= 0, ans = 0;
    for (int i = 0;i < A.size();i++) {
        if (A[i] == state) {
            ans++;
            state = 1 - state;
        }
    }
    return ans;
}


int main(){



    return 0;
}       