#include <bits/stdc++.h>

using namespace std;

// Given a list of weights [w1 , w2 , . . . , wn ], 
// determine all sums that can be constructed using the weights


//possible[i][j]: quiero sumar i usando los primeros j weights

const int k = 4;
int w[k+1] = {0,1,3,3,5};
const int x = 12;
bool possible[x+1][k+1];

void printPossible(){
    for(int i = 0; i <= x; i++){
        for(int j = 1; j <= k; j++){
            cout << possible[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initialize(){
    for(int i = 0; i <= x; i++)
        for(int j = 1; j <= k; j++)
            possible[i][j] = false;
}

void knapsack(){
    possible[0][0] = true;//sin usar ningún peso, puedo sumar 0

    for(int j = 0; j <= k; j++){
        possible[0][j] = true;
    } 
        
    printPossible();

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= k; j++){
            if(i-w[j] >= 0)
                possible[i][j] = possible[i-w[j]][j-1];
            possible[i][j] |= possible[i][j-1];
        }
    }
}


void print(){
    cout << "\t";

    for(int i = 0; i <= k; i++){
        for(int j = 1; j <= i; j++){
            cout << w[j];
        }
        cout << "\t";
    }
    cout << "\n";

    for(int i = 0; i <= x; i++){
        cout << i << "\t";
        for(int j = 0; j <= k; j++){
            cout << possible[i][j] << "\t";
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