#include <bits/stdc++.h>

using namespace std;
#define cn(x) cout << #x << " = " << x << endl;

bool isOdd(int n){
    return n % 2;
}

bool hasPalindromePermutation(string s){
    int n = s.size();
    vector<int> counter(26);
    bool allowOneOddChar = isOdd(n);
    for(char c : s){
        counter[c - 'a']++;
    }
    for(int x : counter){
        if(isOdd(x)){
            if(allowOneOddChar){
                allowOneOddChar = false;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n; cin >> n; cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        if(hasPalindromePermutation(s)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}