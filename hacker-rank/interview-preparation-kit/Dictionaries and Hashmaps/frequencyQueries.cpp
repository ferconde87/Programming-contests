#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    unordered_map<int, int> map;
    unordered_map<int, unordered_set<int> > fs;
    vector<int> answer;
    for(vector<int> q : queries){
        int x = q[1];
        if(q[0]==1){
            //insert
            auto it = map.find(x);
            if(it != map.end()){
                auto itFreqToDelete = fs.find(it->second);
                itFreqToDelete->second.erase(x);
                it->second++;
                auto itFreqToAdd = fs.find(it->second);
                if(itFreqToAdd!=fs.end()){
                    itFreqToAdd->second.insert(x);
                }else{
                    fs[it->second] = unordered_set<int>{x};
                }
            }else{
                map[x] = 1;
                auto itFreq = fs.find(1);
                if(itFreq != fs.end()){
                    itFreq->second.insert(x);
                }else{
                    fs[1] = unordered_set<int>{x};
                }
            }
        }else if(q[0]==2){
            //delete
            auto it = map.find(x);
            if(it != map.end()){
                auto itFreqToDelete = fs.find(it->second);
                //delete element
                itFreqToDelete->second.erase(x);
                it->second--;
                if(it->second == 0){
                    map.erase(it);
                }else{
                    auto itFreqToAdd = fs.find(it->second);
                    if(itFreqToAdd != fs.end()){
                        itFreqToAdd->second.insert(x);
                    }else{
                        fs[it->second] = unordered_set<int>{x};
                    }
                }
            }
        }else{
            auto itCheck = fs.find(x);
            if(itCheck != fs.end()){
                if(!itCheck->second.empty()){
                    answer.push_back(1);
                }else{
                    answer.push_back(0);
                }
            }else{
                answer.push_back(0);
            }
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

