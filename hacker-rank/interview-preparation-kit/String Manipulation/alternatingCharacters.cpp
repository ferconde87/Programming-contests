#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int answer = 0;
    bool lastA = false;
    bool lastB = false;
    for(char c : s){
        if(c=='A'){
            lastB = false;
            if(lastA){
                answer++;
            }else{
                lastA = true;
            }
        }else{
            lastA = false;
            if(lastB){
                answer++;
            }else{
                lastB = true;
            }
        }
    }    
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

