#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)

// Space Complexity O(N)

int removeElement(vector<int> &A, int B) {
    vector<int> temp;
    for(int x : A)
        if(x != B) temp.push_back(x);
    A = temp;
    return A.size();
}


int main(){


    return 0;
}