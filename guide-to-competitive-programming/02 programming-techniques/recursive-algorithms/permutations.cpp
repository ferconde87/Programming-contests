#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

void print(vector<int> v){
    cout << "[ ";
    for(unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

//global variables
const int n = 3;
vector<int> permutation;
bool chosen[n+1];


// Each function call appends a new element to permutation and records that it
// has been included in chosen. If the size of permutation equals the size of the
// set, a permutation has been generated.
void search(){
    if(permutation.size()==n){
        //process permutation
        print(permutation);
    }else{
        for(int i = 1; i <= n; i++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){

    search();
    
    cout << "\n";
    // Note that the C++ standard library also has the function next_permutation
    // that can be used to generate permutations. The function is given a permutation, and
    // it produces the next permutation in lexicographic order. The following code goes
    // through the permutations of {1, 2, . . . , n}:
    vector<int> p;
    for(int i = 1; i <= n; i++) p.push_back(i);
    do{
        for(auto e : p) cout << e << " ";
        cout << "\n";
    }while (next_permutation(p.begin(), p.end()));
    cout << "\n";

    //other way of writing the above do-while loop
    while(next_permutation(p.begin(), p.end())){
        for(auto e : p) cout << e << " ";
        cout << "\n";
    }

    return 0;
}