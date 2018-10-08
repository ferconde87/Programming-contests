#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N)
// Space Complexity O(N)

int diffPossible(vector<int> &A, int B) {
    unordered_set<int> s;
    for(int x : A){
        if(s.find(x+B) != s.end() || s.find(x-B) != s.end())
            return true;
        s.insert(x);
    }
        
    return false;
}


int main(){


    return 0;
}