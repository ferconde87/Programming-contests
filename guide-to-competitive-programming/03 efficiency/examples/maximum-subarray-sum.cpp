#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int a[N] = {-1,2,4,-3,5,2,-5,2};

int brute_force_N_3(){
    int best = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += a[k];
            }
            best = max(best,sum);
        }
    }
    return best;
}

int brute_force_N_2(){
    int best = 0;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = i; j < N; j++){
            sum += a[j];
            best = max(best,sum);
        }
    }
    return best;
}

int solution(){
    int best = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(sum > best){
            best = sum;
        }else if(sum < 0){
            sum = 0;
        }
    }
    return best;
}

int solution2(){
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(a[k],sum+a[k]);
        best = max(best,sum);
    }
    return best;
}


int main(){

    cout << brute_force_N_3() << endl;
    cout << brute_force_N_2() << endl;
    cout << solution() << endl;
    cout << solution2() << endl;

    return 0;
}