#include <bits/stdc++.h>

using namespace std;

// Given a list of weights [w1 , w2 , . . . , wn ], 
// determine all sums that can be constructed using the weights


//disclaimer possible[k][x]: k es la columna y x es la fila (casi siempre lo pienso al reves) 
//en knapsack2 lo resuelvo con possible[i][j] 
// con i fila (sumas) y 
// j columna (primeros j weights) :)

const int n = 4;
int w[n+1] = {0,1,3,3,5};
const int m = 12;
bool possible[m+1][n+1];

void initialize(){
    for(int i = 0; i <= m; i++)
        for(int k = 1; k <= n; k++)
            possible[i][k] = false;
}

void knapsack(){
    possible[0][0] = true;//sin usar ningún peso, puedo sumar 0
    for(int k = 1; k <= n; k++){
        for(int x = 0; x <= m; x++){
            if(x-w[k]>=0){
                possible[x][k] = possible[x-w[k]][k-1];
            }
            possible[x][k] |= possible[x][k-1];
        }
    }
}

void print(){
    cout << "\t";
    for(int x = 0; x <= m; x++) cout << x << "\t";cout << "\n";//sums
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= k; i++) cout << w[i];cout << "\t";//first k wieghts
        for(int x = 0; x <= m; x++){
            cout << possible[x][k] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    initialize();
    knapsack();
    print();

    return 0;
}