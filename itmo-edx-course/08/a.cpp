#include <fstream>
#include <iostream>
#include <algorithm>

#define cn(x) cout << #x << " = " << x << endl;

using namespace std;

//naive solution => TLE

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    int count = 2;//por N % 1 == 0 y por N % N == 0
    int maxSol = 2;
    int maximal = 2;
    for(int k = 4; k <= N; k++){
        int i = k;
        for(int j = 2; j < i; j++){
            if((i % j) == 0) count++;
        }
        if(count > maxSol){
            maxSol = count;
            maximal = i;
        }
        count = 2;
    }
    fout << (N - maximal + 1);

    return 0;
}