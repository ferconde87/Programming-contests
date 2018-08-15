#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int solve(int n){
    int answer = 0;
    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++){
                for(int d = 0; d < 10; d++){
                    if(a == d && b == c){
                        continue;
                    } 
                        
                    int x = 1000*a+100*b+10*c+d;
                    if(x % n == 0){
                        answer++;
                    }
                    
                }
            }
        }
    }
    return answer;
}

int solve2(int n){
    int answer = 0;
    int number = n;
    while(number < 10000){
        int d = (number % 10);
        int c = (number % 100) - d;
        c /= 10;
        int b = (number % 1000) - 10*c - d;
        b /= 100;
        int a = number - 100*b - 10*c - d;
        a /= 1000;
        number += n;  
        if(a == d && b == c){
            continue;
        } 
        answer++;
    }
    return answer;
}

int main(){
    int t; cin >> t;//test cases
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        cout << "solve\t" << solve(n) << endl;
        cout << "solve2\t" << solve2(n) << endl;
    }

    return 0;
}