#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    while(A.size() > 0 && *A.begin() == 0) A.erase(A.begin());
    for(auto it = A.rbegin(); it != A.rend(); ++it){
        if(++*it < 10) break;
        *it = 0;
    }
    if(A.size() == 0 || A.front() == 0){
        A.insert(A.begin(), 1);
    }
    return A;
}

int main(){

    return 0;
}