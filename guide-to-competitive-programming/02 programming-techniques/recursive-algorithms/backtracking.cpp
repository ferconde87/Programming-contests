#include <bits/stdc++.h>

// using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


// As an example, consider the problem of calculating the number of ways n queens
// can be placed on an n × n chessboard so that no two queens attack each other

// The search begins by calling search(0). The size of the board is n, and the
// code calculates the number of solutions to count. The code assumes that the rows
// and columns of the board are numbered from 0 to n − 1. When search is called
// with parameter y, it places a queen on row y and then calls itself with parameter
// y +1. Then, if y = n, a solution has been found, and the value of count is increased
// by one.

int count = 0;
int n = 4;
int col[4];
int diag1[6];
int diag2[6];

void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}


int main(){
    search(0);
    std::cout << count << std::endl;

    return 0;
}