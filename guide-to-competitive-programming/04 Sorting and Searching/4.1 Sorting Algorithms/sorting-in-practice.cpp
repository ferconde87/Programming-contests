#include <bits/stdc++.h>

using namespace std;

void print(int *a, int n){
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

struct point {

    point(int x=0, int y=0): x(x), y(y){
    };

    int x, y;
    bool operator<(const point &p) {
        if (x == p.x) return y < p.y;
        else return x < p.x;
    }
};

// Comparison Functions
bool comp(point a, point b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

// sorts strings primarily by length and secondarily by alphabetical
bool compString(string a, string b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
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

    ////
    vector<tuple<int,int,int> > w;
    w.push_back(make_tuple(2,1,4));//w.push_back({2,1,4});
    w.push_back(make_tuple(1,5,3));// w.push_back({1,5,3});
    w.push_back(make_tuple(2,1,3));// w.push_back({2,1,3});
    sort(w.begin(), w.end());
    int x = get<1>(w[0]);
    for(int i = 0; i < w.size(); i++){
        cout << "(" << get<0>(w[i]) << "," << get<1>(w[i]) << "," << get<2>(w[i]) << ") ";
    }
    cout << endl;

    // sorting using struct point
    const point p1(1,5);
    const point p2(2,3);
    const point p3(1,2);

    vector<point> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    // sort(vp.begin(), vp.end());// it works, but you have to compile with -fpermisive
    sort(vp.begin(), vp.end(), comp);
    for(auto e : vp) cout << "(" << e.x << "," << e.y << ")"; cout << "\n";
    // result: [(1,2),(1,5),(2,3)]

    vector<string> vs = {"pepe", "pep", "hola", "mundo"};
    sort(vs.begin(), vs.end(), compString);
    for(auto s : vs) cout << s << " ";cout << "\n";

    //classic sort
    sort(vs.begin(), vs.end());
    for(auto s : vs) cout << s << " ";cout << "\n";

    return 0;
}