#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

default_random_engine genGlobal;
uniform_int_distribution<int> distGlobal;
int counter = 0;

int android;

bool bloodTestIsPositive(int start, int end){
    counter++;
    return (start >= android && end <= android);
}


int test(int from, int to){
    if(to < from) return -1;
    int mid = (to + from) / 2;
    if(mid == android) return mid;
    bool result = bloodTestIsPositive(from, mid);
    if(result){
        test(from, mid-1);
    }else{
        test(mid+1, to);
    }
}

int main(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    genGlobal = generator;

    uniform_int_distribution<int> distPassenger(1000000,100000000);
    int passenger = distPassenger(genGlobal);
    uniform_int_distribution<int> distribution(1,passenger);
    distGlobal = distribution;
    android = distGlobal(genGlobal);
    cout << "some random numbers between 1 and 10: ";
    for (int i=0; i<10; ++i)
        cout << distribution(generator) << " ";
    cout << endl;

    cn(passenger);
    cn(android);

    test(0, passenger);

    cout << "Llamadas a funcion bloodTestIsPositive: " << counter << endl;


    return 0;
}