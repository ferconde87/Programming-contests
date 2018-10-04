#include <bits/stdc++.h>

using namespace std;

//Time Complexity: O(A*sqrt(A))

//Space Complexity O(1)

bool isPrime(int x){
    int m = (int)sqrt(x);
    for(int i = 2; i <= m; i++){
        if(x % i == 0) return false;
    }
    return true;
}

vector<int> primesum(int A) {
    int mid = A/2;
    int target = 1;
    for(int i = 2; i <= mid; i++){
        if(!isPrime(i)) continue;
        int target = A - i;
        if(isPrime(target)) return {i, target};
    }
    return vector<int>();
}


int main(){


    return 0;
}