#include <bits/stdc++.h>

using namespace std;

//Correct Answer on http://www.spoj.com/problems/ELIS/
int length[10000];
int solve(int *a, int n){
    for (int k = 0; k < n; k++) {
        length[k] = 1;
        for (int i = 0; i < k; i++) {
            if (a[i] < a[k]) {
                length[k] = max(length[k],length[i]+1);
            }
        }
    }

    return *max_element(length, length+n);
}

int main(){

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve(a, n) << endl;

    return 0;
}
