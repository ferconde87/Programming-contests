#include <bits/stdc++.h>

using namespace std;

vector<int> Ans;
void stepnumRec(int x, int N, int M){
    if(x > M) return;
    if(x >= N && x <= M) Ans.push_back(x);
    int last = x % 10;
    if(last > 0){
        stepnumRec(x*10+last-1, N, M);
    }
    if(last < 9){
        stepnumRec(x*10+last+1, N, M);
    }
}

vector<int> stepnum(int A, int B) {
    if(A == 0) Ans.push_back(0);
    for(int i = 1; i < 10; i++){
        stepnumRec(i, A, B);
    }
    sort(Ans.begin(), Ans.end());
    return Ans;
}

int main(){


    return 0;
}