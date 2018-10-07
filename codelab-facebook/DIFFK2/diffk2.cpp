#include <bits/stdc++.h>

using namespace std;

int diffPossible(const vector<int> &A, int B) {
    unordered_set<int> hashSet;
    for(int x : A){
        if(hashSet.find(x + B) != hashSet.end() || hashSet.find(x - B) != hashSet.end()){
            return 1;
        }
        else{
            hashSet.insert(x);
        }
    }
    return 0;
}


int main(){


    return 0;
}