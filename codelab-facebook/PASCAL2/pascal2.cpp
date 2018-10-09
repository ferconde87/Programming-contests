#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int A) {
    if(!A) return {1};
    vector<int> cur({1,1});
    vector<int> last({1});
    for(int i = 2; i <= A; i++){
        last = cur;
        cur.insert(cur.begin(), 1);
        for(int j = 1; j < cur.size() - 1; j++){
            cur[j] = last[j] + last[j-1];
        }
    }
    return cur;
}

int main(){


    return 0;
}