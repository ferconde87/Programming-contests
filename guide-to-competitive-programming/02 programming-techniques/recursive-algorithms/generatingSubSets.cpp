#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

void print(vector<int> v){
    cout << "[ ";
    for(unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

void print(vector< unordered_set<int> > ss){
    cout << "{";
    for(auto s : ss){
        cout << "{ ";
        for(auto x : s){
            cout << x << " ";
        }
        cout << "}";
    }
    cout << "}" << endl;
}

// The following recursive function search can be used to generate the subsets. The
// function maintains a vector
int n = 3;
vector<int> subset;
void search(int k) {
    if (k == n+1) {
        // process subset
        print(subset);
    } else {
        // include k in the subset
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        // don’t include k in the subset
        search(k+1);
    }
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


int main(){
    // When the function search is called with parameter k, it decides whether to
    // include the element k in the subset or not, and in both cases, then calls itself with
    // parameter k + 1. Then, if k = n + 1, the function notices that all elements have been
    // processed and a subset has been generated.
    search(1);
    print(subset);

    //Same idea as search but using unordered_set
    powerSet(1);
    print(ss);




    return 0;
}