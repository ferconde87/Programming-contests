#include <bits/stdc++.h>

using namespace std;

bool isOpen(char c){
    return c == '(' || c == '{' || c == '[';
}

bool isOK(char c, char d){
    if(c=='(') return (d==')');
    if(c=='{') return (d=='}');
    if(c=='[') return (d==']');
    return false;
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> stack;
    for(char c : s){
        if(isOpen(c)){
            stack.push(c);
        }else{
            if(stack.empty()){
                return "NO";
            }
            char top = stack.top();
            stack.pop();
            if(!isOK(top,c)){
                return "NO";
            }
        }
    }
    if(!stack.empty()){
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

