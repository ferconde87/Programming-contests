#include  <bits/stdc++.h>

using namespace std;

long long solve(){
    long long n;
    long long k;
    cin >> n >> k;
    long long result = 0;
    for(int i = 1; i <= n; i++){
        if(result + i == k)
            if(k > 1) result++;// - (i - 1) + i = 1 </conviene sumar el actual y descontar la visita anterior/>
            else continue; 
        else result += i;
    }
    return result;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++)
        cout << solve() << endl;
    return 0;
}