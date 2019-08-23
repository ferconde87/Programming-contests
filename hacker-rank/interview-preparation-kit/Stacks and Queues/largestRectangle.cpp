#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<int> heights;
    stack<int> indexes;
    heights.push(h[0]);
    indexes.push(0);
    int n = h.size();
    int max_value = INT_MIN;
    for(int i = 1; i < n; ++i){
        int next = h[i]; 
        if(next > heights.top()){
            heights.push(next);
            indexes.push(i);
        }else if(next < heights.top()){
            int j = i;
            while(!heights.empty() && next < heights.top()){
                j = indexes.top();
                int value = heights.top() * (i - j);
                max_value = max(max_value, value);
                heights.pop();
                indexes.pop();
            }
            if(heights.empty() || heights.top() < next){
                heights.push(next);
                indexes.push(j);
            }
        }else{//next == heights.top()
            continue;
        }
    }
    while(!heights.empty()){
        int value = heights.top()*(n - indexes.top());
        max_value = max(max_value, value);
        heights.pop();
        indexes.pop();
    }
    return max_value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

