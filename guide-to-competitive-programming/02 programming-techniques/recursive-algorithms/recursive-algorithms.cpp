#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

//g++ -std=c++11 -O2 -Wall a.cpp -o executableName

// RecursiveAlgorithms

void GeneratingPermutations(){

}

void print(vector<int> v){
    cout << "[ ";
    for(unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

int n = 3;
vector<int> subset;
void search(int k) {
    if (k == n+1) {
        // process subset
        print(subset);//or just print it :P
    } else {
        // include k in the subset
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        // don’t include k in the subset
        search(k+1);
    }
}

void print(vector< unordered_set<int> > ss){
    cout << "{";
    for(auto s : ss){
        cout << "{";
        for(auto x : s){
            cout << x << " ";
        }
        cout << "}";
    }
    cout << "}" << endl;
}

unordered_set<int> s;
vector<unordered_set<int> > ss;
void powerSet(int k){
    if(k == n+1){
        ss.push_back(s);
    }else{
        s.insert(k);
        powerSet(k+1);
        s.erase(k);
        powerSet(k+1);
    }
}


void GeneratingSubsets(){
    vector<int> subset;
    search(1);
    powerSet(1);
    print(ss);
}

void RecursiveAlgorithms(){
    GeneratingSubsets();
    GeneratingPermutations();
}




int main(){
    RecursiveAlgorithms();
}