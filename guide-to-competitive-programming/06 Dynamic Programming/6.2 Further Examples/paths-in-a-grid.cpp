#include <bits/stdc++.h>

using namespace std;
//Elegir N y M suficientemente grandes para cubrir todos los casos de testeo
const int N = 100;
const int M = 100;

int solve(){
    int n; int m;
    int matrix[N][M];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    
    int dp[n+1][m+1];
    for(int i = 1; i <= n; i++) dp[i][0] = 0;//0s en 1era columna
    for(int j = 1; j <= m; j++) dp[0][j] = 0;//0s en 1era fila

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = matrix[i][j] + max(dp[i-1][j], dp[i][j-1]);
    
    return dp[n][m];
}

int main(){

    cout << solve() << endl;

}