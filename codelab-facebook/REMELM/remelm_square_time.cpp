#include <bits/stdc++.h>

using namespace std;

// Time Complexity O(N^2)

// Space Complexity O(1)

int removeElement(vector<int> &A, int B) {
    auto it = A.begin();
    while(it != A.end()){
        if(*it == B){
            it = A.erase(it);
        }else{
            it++;
        }
    }
    return A.size();
}

//trying to improve
int removeElement2(vector<int> &A, int B) {
    auto it = A.begin();
    while(it != A.end()){
        if(*it == B){
            auto itEnd = it;
            itEnd++;
            while(itEnd != A.end() && *itEnd == B) itEnd++;
            it = A.erase(it, itEnd);
        }else{
            it++;
        }
    }
    return A.size();
}

int main(){


    return 0;
}