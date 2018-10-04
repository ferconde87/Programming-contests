#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

//https://codelab.interviewbit.com/problems/primesum/ > solution.cpp:5:1: error: 'bitset' does not name a type

//funciona OK en g++ (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609


bitset<N> make_sieve(int n){
    bitset<N> sieve;
    sieve.set();
    sieve.reset(0);
    sieve.reset(1);
    int mid = n / 2;
    for(int i = 2; i < mid; i++){
        if(sieve[i]){
            for(int j = i; j*i <= n; j++){
                sieve.reset(j*i);
            }
        }
    }
    return sieve;
}

void print_sieve(bitset<N> sieve, int n){
    for(int i = 0; i < n; i++){
        if(sieve[i]) cout << i << " ";
    }
    cout << endl;
}

vector<int> primesum(int A){
    int mid = A / 2;
    bitset<N> sieve = make_sieve(A);
    for(int i = 2; i <= mid; i++){
        if(sieve[A-i]) return {i, A-i};
    }
    return {};
}

int main(){

    bitset<N> prueba = make_sieve(100);
    print_sieve(prueba, 100);

    vector<int> result = primesum(12);
    cout << *result.begin() << " " << *(result.end()-1) << endl;

    return 0;
}