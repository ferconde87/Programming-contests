#include <bits/stdc++.h>

using namespace std;

//cuentoso, sin usar variables para cada coordenada. Usando el "indice" del for
//Concentrandose en el "start" de cada diagonal y notando que siempre es (X_anterior + 1, Y_anterior - 1) 

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > result;
    for(int j = 0; j < n; j++){
        vector<int> cur;
        for(int i = 0; i <= j; i++){
            cur.push_back(A[i][j-i]);
        }
        result.push_back(cur);
    }
    for(int a = n-1; a > 0; a--){
        vector<int> cur;
        for(int b = 1; b <= a; b++){
            cur.push_back(A[n-a+b-1][n-b]);
        }
        result.push_back(cur);
    }
    return result;
}

int main(){




    return 0;
}