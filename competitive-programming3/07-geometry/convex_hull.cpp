#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

double dist(pt a, pt b){
  return sqrt(abs(a.x-b.x)+abs(a.y-b.y));
}

int main(){

  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    int n;
    cin >> n;
    vector<pt> v(n);
    for(int i=0; i<n; ++i){
      pt p;
      cin >> p.x >> p.y;
      v[i] = p;
    }
    convex_hull(v);
    cout << "Case #" << k << ": " << endl;
    cout << "Vertices = " << v.size() << endl;
    for(pt p : v) cout << p.x << " " << p.y << endl;
    if(v.size() > 1) v.push_back(v[0]);
    double perimeter = 0;
    for(int i=0; i<n; ++i)
      perimeter += dist(v[i], v[i+1]);
    cout << "Perimeter = " << perimeter << endl;
  }

  return 0;
}
