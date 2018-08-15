#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int funScore(string s){
    vector<int> counter(26);
    int n = s.size();
    for(char c : s){
        counter[c - 'a']++;
    }
    int sizeOfPalindrome = 0;
    for(int i = 0; i < 26; i++){
        int amount = counter[i];
        if(amount == 0) continue;
        if(counter[i] % 2 == 0) sizeOfPalindrome += counter[i];
        else sizeOfPalindrome += counter[i]-1;
    }
    int halfA = sizeOfPalindrome / 2;
    int halfB = halfA;
    if(halfA % 2 == 1 && sizeOfPalindrome <= n-2){
        halfA++;
        halfB--;
    }

    if(sizeOfPalindrome <= n-2){
        return (halfA+1)*(halfB+1);
    }else if(sizeOfPalindrome == n-1){
        return (halfA+1)*halfB;
    }
    return halfA*halfB;
}

int main(){
    int t; cin >> t;//test cases
    cin.ignore();
    for(int i = 0; i < t; i++){
        string s; getline(cin, s);
        cn(s);
        cout << funScore(s) <<  endl;
    }
    return 0;
}