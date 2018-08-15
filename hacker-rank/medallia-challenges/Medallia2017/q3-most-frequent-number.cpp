#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int most_frequent_number(int *a, int n){
    sort(a, a+n);
    int counter = 1;
    int max_frequent = 1;
    int answer = a[0];
    for(int i = 0; i < n-1; i++){
        if(a[i]==a[i+1]){
            counter++;
            if(counter > max_frequent){
                answer = a[i];
                max_frequent = counter;
            }
        }else{
            counter = 1;
        }
    }
    return answer;
}

int most_frequent_number2(int *a, int n){
    map<int, int> map;
    for(int i = 0; i < n; i++){
        int cur = a[i];
        auto it = map.find(cur);
        if(it == map.end()){
            map[cur] = 1;
        }else{
            it->second++;
        }
    }

    int counter = 0;
    int max_frequent = 0;
    int answer = 0;
    for(auto it = map.begin(); it != map.end(); ++it){
        if(it->second > max_frequent){
            max_frequent = it->second;
            answer = it->first;
        }
    }
    return answer;
}

int most_frequent_number3(int *a, int n){
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){
        int cur = a[i];
        auto it = map.find(cur);
        if(it == map.end()){
            map[cur] = 1;
        }else{
            it->second++;
        }
    }

    int counter = 0;
    int max_frequent = 0;
    int answer = INT_MAX;
    for(auto it = map.begin(); it != map.end(); ++it){
        if(it->second >= max_frequent && it->first < answer){
            max_frequent = it->second;
            answer = it->first;
        }
    }
    return answer;
}


int main(){
    int t; cin >> t;//test cases
    for(int k = 0; k < t; k++){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << most_frequent_number3(a, n) << endl;
        cout << most_frequent_number2(a, n) << endl;
        cout << most_frequent_number(a, n) << endl;
    }


    return 0;
}