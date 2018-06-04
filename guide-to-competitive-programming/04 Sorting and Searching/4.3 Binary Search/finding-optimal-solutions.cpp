#include <bits/stdc++.h>

using namespace std;

int k = 5;
int const n = 12;
int arr[n] = {1,3,3,4,5,5,6,9,10,12,12,15};

//return true when value of arr at index is >= k
bool valid(int index){
    return arr[index] >= k;
}

int binarySearch(int x){
    int k = 0;
    for(int b = n/2; b >=1; b/=2){
        if(b+k < n && arr[b+k] <= x) k+=b;
    }
    if(arr[k]==x) return k;
    return -1;
}

int binarySearchStrategy(){
    int x = -1;
    for(int b = n; b >=1; b/=2){
        while(!valid(x+b)) x+=b;
    }
    return x+1;
}

int main(){
    
    cout << binarySearchStrategy() << endl;//4
    k = 6;
    cout << binarySearchStrategy() << endl;//6
    return 0;
}