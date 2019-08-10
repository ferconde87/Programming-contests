#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n = s.size();
    int counter = 0;
    for(int l = 1; l < n; l++){
        unordered_map<string, int> map;
        for(int i = 0; i <= n - l; i++){
            string subs = s.substr(i,l);
            sort(subs.begin(), subs.end());
            auto it = map.find(subs);
            if(it == map.end()){
                map.insert(make_pair(subs,1));
            }else{
                it->second++;
            }
        }
        for(auto pair : map){
            int times = pair.second;
            if(times > 1){
                counter += times*(times-1) / 2;
            }
        }
    }
    return counter; 
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

