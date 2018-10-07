#include <bits/stdc++.h>

using namespace std;

unordered_set<long long> values;

int colorfulRecursive(int index, int len, int A, string & s){
    
    if(len > s.size()) return 1;
    
    if(index + len > s.size()){
        return colorfulRecursive(0, len+1, A, s);
    }
    long long num = 1;
    for(int k = 0; k < len; k++){
        num *= (long long)(s[index+k] - '0');
    }
    auto it = values.find(num);
    if(it != values.end()){
        return 0;
    }else{
        values.insert(num);
        return colorfulRecursive(index+1, len, A, s);
    }
    
    return 1;
    
}

int colorful(int A) {
    int len = 0;
    int temp = A;
    string s = to_string(A);
    while(temp){
        temp /= 10;
        len++;
    }
    
    return colorfulRecursive(0, 1, A, s);
}

int main(){

    cout << colorful(234) << endl;

    return 0;
}