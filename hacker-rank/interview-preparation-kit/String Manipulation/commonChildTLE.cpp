#include <bits/stdc++.h>

using namespace std;

int memo[5001][5001];
int commonChild(string s1, int index1, string s2, int index2){

    if(index1 == 0 || index2 == 0){
        if(s1[index1] == s2[index2]){
            return 1;
        }else{
            return 0;
        }
    }

    if(memo[index1][index2]!= -1){
        return memo[index1][index2];
    }

    if(s1[index1]==s2[index2]){
        memo[index1][index2] = 1 + commonChild(s1,index1-1,s2,index2-1);
    }else{
        memo[index1][index2] = max(commonChild(s1,index1-1,s2,index2), commonChild(s1,index1,s2,index2-1));
    }

    return memo[index1][index2];
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

    memset(memo,-1,5001*5001);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

