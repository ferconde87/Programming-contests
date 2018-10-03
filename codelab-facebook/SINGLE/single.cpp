#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(N)

int singleNumber(const vector<int> &A) {
    unordered_set<int> hashSet;
    for(int elem : A){
        auto it = hashSet.find(elem);
        if(it != hashSet.end()){
            hashSet.erase(it);
        }else{
            hashSet.insert(elem);
        }
    }
    return *hashSet.begin();
}


int main(){

    return 0;
}
