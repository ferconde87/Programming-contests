#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int main(){

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