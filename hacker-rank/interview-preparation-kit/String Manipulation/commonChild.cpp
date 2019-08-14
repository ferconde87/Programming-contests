#include <bits/stdc++.h>

using namespace std;

int memo[5001][5001];
int commonChild(string s1, int index1, string s2, int index2){
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i]==s2[j]){
                memo[i+1][j+1] = 1 + memo[i][j]; 
            }else{
                memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
            }
        }
    }
    return memo[s1.size()][s2.size()];
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    return commonChild(s1,s1.size()-1,s2,s2.size()-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    memset(memo,0,5001*5001);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

