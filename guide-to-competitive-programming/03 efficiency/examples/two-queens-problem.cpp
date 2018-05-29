#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int solve(int n){
    int col[n];
    int diag1[n+n-1];
    int diag2[n+n-1];

    for(int i = 0; i < n; i++){
        col[i] = 0;
    }
    for(int i = 0; i < n+n-1; i++){
        diag1[i] = diag2[i] = 0;
    }

    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            col[y] = diag1[x+y] = diag2[y-x+n-1] = 1;
            for(int x2 = x+1; x2 < n; x2++){
                for(int y2 = 0; y2 < n; y2++){
                    if((col[y2] == 1) || (diag1[x2+y2] == 1) || (diag2[y2-x2+n-1] == 1)) continue;
                    ans++;
                }
            }
            col[y] = diag1[x+y] = diag2[y-x+n-1] = 0;
        }
    }
    return ans;
}

//with bitset
int solve2(int n){
    bitset<200> col;
    bitset<399> diag1;
    bitset<399> diag2;
    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            col[y] = diag1[x+y] = diag2[y-x+n-1] = true;
            for(int x2 = x+1; x2 < n; x2++){
                for(int y2 = 0; y2 < n; y2++){
                    if(col[y2] || diag1[x2+y2] || diag2[y2-x2+n-1]) continue;
                    ans++;
                }
            }
            col[y] = diag1[x+y] = diag2[y-x+n-1] = false;
        }
    }
    return ans;
}


int main(){

    cout << "Brute force solution" << endl;
    for(int i = 1; i <= 8; i++){
        cout << i << " = " << solve(i);cout << endl;
    }
    cout << endl;

    cout << "Brute force solution 2" << endl;
    for(int i = 1; i <= 8; i++){
        cout << i << " = " << solve2(i);cout << endl;
    }
    cout << endl;

    //O(N)
    // q(n)    = q(n − 1) + (2n − 1)(n 2 − 3(n − 1) − 1) − (n − 1)(n − 2)
    //         = q(n − 1) + 2(n − 1)2 (n − 2),
    int n = 10;
    int q[n+1];
    q[0] = 0;
    for(int i = 1; i <= n; i++){
        q[i] = q[i-1] + 2*(i-1)*(i-1)*(i-2);
        cout << i << " = " << q[i] << endl;
    }
    cout << q[n] << endl;   

    //O(1)
    int n_4 = pow(n,4);
    cn(n_4)
    int n_3 = pow(n,3);
    cn(n_4)
    int result = n_4*0.5 - n_3*1.6666666 + 3*(n*n)*0.5 - n*0.3333333;
    cn(result)
    
    return 0;
}