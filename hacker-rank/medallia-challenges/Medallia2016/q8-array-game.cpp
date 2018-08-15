#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


bool allEqual(vector<int> & a, int n){
    for(int i = 0; i < n-1; i++){
        if(a[i]!=a[i+1]) return false;
    }
    return true;
}

int arrayGame(vector<int> & a, int n){
    int result = 0;
    while(!allEqual(a,n)){
        int min_e = *min_element(a.begin(), a.end());
        auto it_max_e = max_element(a.begin(), a.end());
        int add_amount = *it_max_e - min_e;
        result += add_amount;
        for(auto it = a.begin(); it != a.end(); ++it){
            if(it != it_max_e) *it += add_amount;
        }
    }
    return result;
}

bool allEqual(int *a, int n){
    for(int i = 0; i < n-1; i++){
        if(a[i]!=a[i+1]) return false;
    }
    return true;
}

int arrayGame(int *a, int n){
    int result = 0;
    while(!allEqual(a,n)){
        int min_e = *min_element(a, a+n);
        auto it_max_e = max_element(a, a+n);
        int add_amount = *it_max_e - min_e;
        result += add_amount;
        for(auto it = a; it != a+n; ++it){
            if(it != it_max_e) *it += add_amount;
        }
    }
    return result;
}

int main(){
    int t; cin >> t;//test cases
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> a(n);
        // int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << arrayGame(a, n) << endl;
    }
    return 0;
}