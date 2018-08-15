#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

bool isSet(int index, int number){
    return ((1 << index) & number);
}


int amountOfOperations(int n){
    int result = 0;
    for(int i = 0; i < 32; i++){
        if(isSet(i, n)) result += i+1;
    }
    return result;
}

int main(){
    int t; cin >> t;//test cases
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        cout << amountOfOperations(n) << endl;
    }
    return 0;
}