#include <bits/stdc++.h>

using namespace std;

//O(N LOG N) solution from codeforces: http://codeforces.com/blog/entry/13225
//Assuming Longest NON_STRICTLY increasing SECUENCY
int  solve_n_log_n(int *a, int n){ 
    multiset < int > s;
    multiset < int > :: iterator it;

    for(int i = 0; i < n; i++){   	
        s.insert(a[i]);
        it = s.upper_bound(a[i]);
        if(it != s.end()) s.erase(it);
	}

    return s.size();
}

int main(){

    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];

    cout << solve_n_log_n(a, n) << endl;

    return 0;
}