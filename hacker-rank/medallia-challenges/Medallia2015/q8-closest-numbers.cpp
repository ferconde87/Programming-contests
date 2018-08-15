#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

void closestNumbers(int *numbers, int n){
    sort(numbers, numbers+n);
    int min_diff = INT_MAX;
    for(int i = 0; i < n-1; i++){
        int cur = numbers[i+1] - numbers[i];
        min_diff = min(min_diff, cur);
    }
    for(int i = 0; i < n-1; i++){
        int cur = numbers[i+1] - numbers[i];
        if(cur == min_diff){
            cout << numbers[i] << " " << numbers[i+1] << endl;
        }
    }
}

int main(){
    int n; cin >> n;
    int numbers[n];
    for(int i = 0; i < n; i++) cin >> numbers[i];
    closestNumbers(numbers, n);
    return 0;
}