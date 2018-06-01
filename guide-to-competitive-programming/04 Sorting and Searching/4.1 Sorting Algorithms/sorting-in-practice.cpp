#include <bits/stdc++.h>

using namespace std;

void print(int *a, int n){
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<int> a = {1,3,6,9,9,3,5,9};
    print(a);
    //sort classic, in ascending order
    sort(a.begin(), a.end());
    print(a);
    cout << endl;
    a = {1,3,6,9,9,3,5,9};
    print(a);
    //sort in descending order
    sort(a.rbegin(),a.rend());
    print(a);
    cout << endl;

    ////
    int n = 7; // array size
    int b[] = {4,2,5,3,5,8,3};
    sort(b,b+n);
    print(b, n);
    cout << endl;

    s(b,n)

    string s = "monkey";
    cout << s << endl;
    sort(s.begin(), s.end());
    cout << s << endl;

    ////
    vector<pair<int,int>> v;
    v.push_back({1,5});
    v.push_back({2,3});
    v.push_back({1,2});
    sort(v.begin(), v.end());
    for(auto e : v) cout << "(" << e.first << "," << e.second << ")"; cout << "\n";
    // result: [(1,2),(1,5),(2,3)]
  
    return 0;
}