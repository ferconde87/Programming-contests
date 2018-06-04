#include <bits/stdc++.h>

using namespace std;

const int n = 12;
int arr[n] = {1,3,3,4,5,5,6,9,10,12,12,15};

//precondition array 'arr' must be in sorted order
//return the index of the element x
//if it doesn't exist return -1
int binarySearch(int x){
    int a = 0, b = n-1;
    while (a <= b) {
        int k = (a+b)/2;
        if (arr[k] == x) {
            // x found at index k
            return k;
        }
        if (arr[k] < x) a = k+1;
        else b = k-1;
    }
    return -1;//#404 element not found
}

//another implementation
int binarySearch2(int x){
    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && arr[k+b] <= x) k += b;
    }
    if (arr[k] == x) {
        // x found at index k
        return k;
    }
    return -1;
}


int main(){
    
    cout << binarySearch(9) << endl;//7

    cout << binarySearch2(9) << endl;//7
    cout << binarySearch2(1) << endl;//0
    cout << binarySearch(0) << endl;//-1

    return 0;
}