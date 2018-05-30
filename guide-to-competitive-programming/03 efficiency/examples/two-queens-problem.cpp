#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

//O(n^4)
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

//O(n^4) with bitset
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

//O(n^2)
int solve3(int n){
    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int options = (n - (x + 1)) * n;
            if(x + y < n) options-=y;//diag1
            else options-=(n-1-x);
            if(x>=y)options-=(n-1-x);//diag2
            else options-=(n-1-y);
            options-=(n-x-1);//col (cells column below (x,y))
            ans+=options; 
            cout << options << "\t";//free options per position
        }
        cout << endl;
    }
    return ans;
}

void diag1(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cout << x+y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void diag1len(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(x + y < n){
                cout << x+y << " ";
            }else{
                cout << (n+n-2)-(x+y) << " ";
            }
        }
        cout << endl;
    }    
    cout << endl;
}
//free cells per position for queen 2 without repeating cells in diag2
void diag1options(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(x + y < n){
                cout << y << " ";//x+y-y
            }else{
                cout << n-1-x << " ";//(n+n-2)-(x+y)-((n-1)-y)
            }
        }
        cout << endl;
    }    
    cout << endl;
}

void diag2(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cout << y-x+n-1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void diag2len(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(x>=y){
                cout << n-1+y-x << " ";
            }else{
                // cout << (n+n-2)-(y-x+n-1) << " ";ie n-1-y+x
                cout << n-1-y+x << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//free cells per position for queen 2 without repeating cells in diag2
void diag2options(int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(x>=y){
                cout << n-1-x << " ";//y-x-n-1-y
            }else{
                // cout << (n+n-2)-(y-x+n-1) << " ";ie n-1-y+x
                cout << n-1-y << " ";//n-1-y-x
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    cout << "Brute force solution O(N^4)" << endl;
    for(int i = 1; i <= 8; i++){
        cout << i << " = " << solve(i);cout << endl;
    }
    cout << endl;

    cout << "Brute force solution O(N^4) using bitset" << endl;
    for(int i = 1; i <= 8; i++){
        cout << i << " = " << solve2(i);cout << endl;
    }
    cout << endl;

    cout << "O(N^2) solution count combionations in groups" << endl;
    for(int i = 1; i <= 8; i++){
        cout << i << " = " << solve3(i) << "\n\n";
    }
    cout << "\n\n";

    cout << "O(N)" << endl;
    //q(n) = q(n − 1) + (2n − 1)(n 2 − 3(n − 1) − 1) − (n − 1)(n − 2)
    //     = q(n − 1) + 2(n − 1)2 (n − 2)
    int n = 10;
    int q[n+1];
    q[0] = 0;
    for(int i = 1; i <= n; i++){
        q[i] = q[i-1] + 2*(i-1)*(i-1)*(i-2);
        cout << i << " = " << q[i] << endl;
    }
    cout << q[n] << "\n\n";   

    cout << "O(1)" << endl;
    int n_4 = pow(n,4);
    cn(n_4)
    int n_3 = pow(n,3);
    cn(n_4)
    int result = n_4*0.5 - n_3*1.6666666 + 3*(n*n)*0.5 - n*0.3333333;
    cn(result)

    //Useful calculations to deduce O(N^2) solution
    cout << endl;
    diag1(4);
    diag1len(4);
    diag1options(4);
    diag2(4);
    diag2len(4);
    diag2options(4);
    
    return 0;
}