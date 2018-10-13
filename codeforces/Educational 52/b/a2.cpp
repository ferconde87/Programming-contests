#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int solve(){}

int main(){
    long long n, m;
    cin >> n >> m;
    if(m == 0) cout << n << " " << n << endl;
    else if(m == 1) cout << n-2 << " " << n-2 << endl;
    else{
        long long min_ans = max(n-2*m, (long long)0);
        long long max_ans = n-2;
        long long cur_m = 1;
        long long add = 2;
        long long last_m;
        while(cur_m < m){
            max_ans--;
            cur_m += add;
            add++;
        }
        cout << min_ans << " " << max_ans << endl;
    }
    


    return 0;
}