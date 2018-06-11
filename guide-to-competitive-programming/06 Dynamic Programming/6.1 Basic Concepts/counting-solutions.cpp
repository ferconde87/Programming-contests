#include <bits/stdc++.h>

using namespace std;

int coins[3] = {1,3,4};

int value[3] = {0,0,0};
bool ready[3] = {false, false, false};

int solve(int x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(ready[x]) return value[x];
    int ans = 0;
    for(auto c : coins){
        if(c > x) continue;
        ans += solve(x-c);
    }
    value[x] = ans;
    ready[x] = true;
    return ans;
}


//Iterative solution
//detalle: en solve2 acumulamos el valor de count[i] en ans
int solve2(int x){
    if(x < 0) return 0;
    int count[x+1];
    count[0] = 1;
    for(int i = 1; i <= x; i++){
        int ans = 0;
        for(auto c : coins){
            if(c > i) continue;
            ans += count[i-c];
        }
        count[i] = ans;
    }
    return count[x];
}

//detalle: en solve2 inicializamos count[x+1] con 0's, luego podemos sumar de una en count[x] += ...
int solve3(int n){
    if(n < 0) return 0;
    int count[n+1];
    for(int i = 0; i <= n; i++) count[i] = 0;
    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (auto c : coins) {
            if (x-c >= 0) {
                count[x] += count[x-c];
            }
        }
    }
    return count[n];
}

// Often the number of solutions is so large that it is not required to calculate the
// exact number but it is enough to give the answer modulo m where, for example,
// m = 109 + 7. This can be done by changing the code so that all calculations are
// done modulo m. In the above code, it suffices to add the line
const int m = 1000000007;
int solve3_module_m(int n){
    if(n < 0) return 0;
    int count[n+1];
    for(int i = 0; i <= n; i++) count[i] = 0;
    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (auto c : coins) {
            if (x-c >= 0) {
                count[x] += count[x-c];
                count[x] %= m;
            }
        }
    }
    return count[n];
}



int main(){

    cout << solve(5) << endl;
    cout << solve2(5) << endl;
    cout << solve3(5) << endl;
    cout << solve3_module_m(1000) << endl;

    return 0;
}