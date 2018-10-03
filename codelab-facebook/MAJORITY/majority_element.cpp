#include <bits/stdc++.h>

using namespace std;

//Time complexity: O(N)

//Space complexity: O(N)

int majorityElement(const vector<int> &A) {
    int n = A.size();
    unordered_map<int, int> amounts;
    for(int elem : A){
        auto it = amounts.find(elem);
        if(it != amounts.end()){
            it->second++;
        }else{
            amounts[elem] = 1;
        }
    }
    int majorityElement;
    int maxValue = 0;
    for(auto pair : amounts){
        if(pair.second > maxValue){
            maxValue = pair.second;            
            majorityElement = pair.first;
        }
    }
    return majorityElement;
}

int main(){


    return 0;
}