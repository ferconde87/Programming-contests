#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

const int N = 8;
int a[N] = {1,3,8,2,9,2,5,6};

void print(){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// After the first round of bubble sort, the largest element will be in the correct
// position, and more generally, after k rounds, the k largest elements will be in the
// correct positions. Thus, after n rounds, the whole array will be sorted.
void bubbleSort(){
    for(int i = 0; i < N-1; i++)
        for(int j = 0; j < N-1; j++)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
}

void swapIfItIsSmaller(){
    print();
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
    print();
}


void swapIfItIsGreater(){
    print();
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            if(a[i] < a[j])//<= descending order
                swap(a[i], a[j]);
    print();
}


int main(){

    print();
    bubbleSort();
    print();
    cout << endl;
    swapIfItIsSmaller();
    cout << endl;
    swapIfItIsGreater();

    return 0;
}