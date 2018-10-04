#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

int coverPoints(vector<int> &X, vector<int> &Y) {
    int n = X.size();
    if(n != Y.size()) return -1;
    int result = 0;
    for(int i = 0; i < n - 1; ++i){
        result += max(abs(X[i]-X[i+1]), abs(Y[i]-Y[i+1]));
    }
    return result;
}


int main(){

    return 0;
}
