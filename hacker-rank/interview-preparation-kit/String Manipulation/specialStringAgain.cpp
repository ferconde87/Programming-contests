#include <bits/stdc++.h>

using namespace std;

long countConsecutives(int n, string s){
    int i = 0;
    long answer = 0;
    while(i < n){
        long size = 1;
        while(i+1 < n && s[i]==s[i+1]){
            size++;
            i++;
        }
        i++;
        for(int l = 1; l <= size; l++){
            if(i-1 >= 0 && i+l < n && s[i-1]==s[i+l]){
                answer++;
            }else{
                break;
            }
        }

        answer += size*(size+1)/2;
    }
    return answer;
}

long countConsecutivesExceptMid(int n, string s){
    int mid = n/2;
    if(n%2==0) mid--;
    long answer = 0;
    for(int i = 1; i < n-1; i++){
        for(int l = 1; l <= mid; l++){
            if(i-l >= 0 && i+l < n && s[i]!=s[i-l] && s[i-l]==s[i+l]){
                cout << "i = " << i << " / l = " << l << endl;
                answer++;
            }else{
                break;
            }
        }
    }
    return answer;
}

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long answer = countConsecutives(n,s);
    cout << answer << endl;
    //answer += countConsecutivesExceptMid(n,s);
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

