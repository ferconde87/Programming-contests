#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

double calculateEfficiencyPercent(double goal, double shoot){
    return roundf((goal/shoot) * 1000) / 10;
}

//c++ convension
//-1: 'a' is less than b
//0: 'a' is equal to b
//1: 'a' is greater than b
int compare(double a, double b){
    double diff = a - b;
    if(abs(diff) < 0.1) return 0;
    if(diff < 0) return -1;
    else return 1;
}

int solve(){
    double efficiency; cin >> efficiency;
    double goal = 0;
    int shoot = 1;
    while(true){
        double cur = calculateEfficiencyPercent(goal, shoot);
        int comparation = compare(cur, efficiency);
        if(comparation == -1) {goal++; shoot++;}
        else if(comparation == 1) shoot++;
        else break;        
    }
    return shoot;
}

// int solve2(){
//     double efficiency; cin >> efficiency;
//     efficiency /= 100;
//     double goal = 0;
//     double shoot = 1;
//     double diff = 1;
//     bool result = diff < 0.05 && diff > -0.05;
//     while(!(diff < 0.05 && diff > -0.05)){
//         double cur = (goal / shoot);
//         diff = cur - efficiency;
//         if(diff < 0.05 && diff > -0.05){
//             return shoot;
//         }else if(diff < 0) goal++;
//         shoot++; 
//     }
//     return -1;
// }


int main(){
    int t; cin >> t;//#tests
    for(int i = 0; i < t; i++){
        cout << solve() << endl;
        // cout << solve2() << endl;
    }
    return 0;
}