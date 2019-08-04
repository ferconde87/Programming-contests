#include <bits/stdc++.h>

using namespace std;

long countA(string s){
    long answer = 0;
    for(char c : s){
        if (c == 'a'){
            answer++;
        } 
    }
    return answer;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long asInString = countA(s);
    long size = s.size();
    long rem = n % size;
    long times = n / size;
    long answer = asInString * times;
    for(int i = 0; i < rem; i++){
        if(s[i] == 'a'){
            answer++;
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

