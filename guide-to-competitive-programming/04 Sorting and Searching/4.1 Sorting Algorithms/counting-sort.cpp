#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int a[N] = {1,3,6,9,9,3,5,9};
int minValue = 1;
// int maxValue = 9;
int m = 9;//{max number (maxValue) in N} - {min number (minValue) in N} + 1
void countingSort(){
    int b[m];
    for(int i = 0; i < m; i++) b[i] = 0;//O(m)

    for(int i = 0; i < N; i++){
        b[a[i]-minValue]++;
    }

    int j = 0;
    for(int i = 0; i < m; i++){//O(m+N)
        while(b[i]>0){
            a[j++] = i+minValue;
            b[i]--;
        }
    }
}

void print(){
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    print();
    countingSort();
    print();
    cout << endl;
    vector<int> v = {1,3,8,2,9,2,5,6};
    copy(v.begin(), v.end(), a);
    print();
    countingSort();
    print();
    
    return 0;
}