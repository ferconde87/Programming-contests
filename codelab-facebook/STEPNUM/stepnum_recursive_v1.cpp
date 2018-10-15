#include <bits/stdc++.h>

using namespace std;

vector<int> Ans;
void dfs(int len, int N, int M, int num = 0) {
    if(num >= N && num <= M) {
        Ans.push_back(num);
    }

    if(len == 0)
    return;
    

    if(num == 0) {
        for(int i = 1; i <= 9; ++i) {
            dfs(len - 1, N, M, i);
        }
        return;
    }

    int last_dig = num%10;
    if(last_dig == 0) {
    
        dfs(len - 1, N, M, (num * 10) + (last_dig + 1));
    
    } else if(last_dig == 9) {
    
        dfs(len - 1, N, M, (num * 10) + (last_dig - 1));
    
    } else {
        dfs(len - 1, N, M, (num * 10) + (last_dig - 1));
        dfs(len - 1, N, M, (num * 10) + (last_dig + 1));
    }
}

vector<int> stepnum(int N, int M) {
    int len = 0;
    int temp = M;
    while(temp) {
        temp /= 10;
        len++;
    }

    Ans.clear();
    dfs(len, N, M);
    sort(Ans.begin(), Ans.end());
    return Ans;
}

int main(){

    vector<int> result = stepnum(100, 2000);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}