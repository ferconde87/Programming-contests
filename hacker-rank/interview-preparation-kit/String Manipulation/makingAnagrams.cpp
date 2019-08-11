#include <bits/stdc++.h>

using namespace std;

vector<int> build_vector(string s){
    vector<int> answer(26,0);
    for(char c : s){
        answer[c - 'a']++;
    }
    return answer;
}

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector<int> v1 = build_vector(a);
    vector<int> v2 = build_vector(b);
    int answer = 0;
    for(int i = 0; i < 26; i++){
        answer += abs(v1[i]-v2[i]);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

