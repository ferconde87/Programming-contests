#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<long> build_powers(long r){
    vector<long> powers;
    powers.push_back(1);
    for(long k = r; k <= 1000000000; k*=r){
        powers.push_back(k);
    }
    return powers;
}

void print(vector<long> & v){
    for(long x : v) cout << x << " ";cout << endl;
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> r2;
    unordered_map<long, long> r3;
    long count = 0;
    for(long v : arr){
        auto it3 = r3.find(v);
        if(it3 != r3.end()){
            count += it3->second;
        }

        long next = v*r;
        auto it2 = r2.find(v);
        if(it2 != r2.end()){
            it3 = r3.find(next);
            if(it3 != r3.end()){
                it3->second += it2->second;    
            }else{
                r3[next] = it2->second;
            }
        }
        
        it2 = r2.find(next);
        if(it2!=r2.end()){
            it2->second++;
        }else{
            r2[next] = 1;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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

