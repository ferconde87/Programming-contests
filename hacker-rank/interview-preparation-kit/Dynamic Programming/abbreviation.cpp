#include <bits/stdc++.h>

using namespace std;

vector<int> make_counter(string & b){
    vector<int> answer(26,0);
    for(char c : b){
        answer[c - 'A']++;
    }
    return answer;
}

bool allLowerTill(string a, int k){
    for(int i = 0; i < k; i++){
        if(isupper(a[i])){
            return false;
        }
    }
    return true;
}

int dp[1001][1001];

int abbreviation(string a, int n, string b, int m){
    if(m == 0){
        if(n == 0 || allLowerTill(a,n)){
            dp[n][m] = 1;
            return 1;
        }else{
            dp[n][m] = 0;
            return 0;
        }
    }
    if(dp[n][m]!= -1){
        return dp[n][m];
    }
    char curA = a[n-1];
    char curB = b[m-1];
    if(isupper(curA)){
        if(curA!=curB){
            dp[n][m] = 0;
        }else{
            dp[n][m] = abbreviation(a,n-1,b,m-1);
        } 
    }else{//curA is lower
        if(toupper(curA)==curB){
            dp[n][m] = abbreviation(a,n-1,b,m-1) || abbreviation(a,n-1,b,m);
        }else{
            dp[n][m] = abbreviation(a,n-1,b,m);
        }
    }
    return dp[n][m];
}

bool searchInDP(){
    for(int i = 0; i < 1001; i++){
        if(dp[i][0]==1){
            return true;
        }
    }
    return false;
}

void print(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            dp[i][j] = -1;
        }
    }
    abbreviation(a,a.size(),b,b.size());
    if(searchInDP()){
        return "YES";
    }else{
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

