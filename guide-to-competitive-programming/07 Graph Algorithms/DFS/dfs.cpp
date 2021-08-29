#include <bits/stdc++.h>

using namespace std;

const int N = 51;
vector<pair<int, int> > adj[N];
int value[N];
vector<int> paths[N];
int max_value = 0;
bool processed[N];
int max_cave = -1;

void dfs(int s, int prev){
  //processed the node. Ex:
  // value[s]+=value[prev];
  // if(value[s] > max_value){
  //   max_value = value[s];
  //   max_cave = s;
  // }
  processed[s] = true;
  for(auto u : adj[s]){
    if (u.first == prev) continue;
    if(processed[u.first]) continue;
    dfs(u.first, s);
  }  
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n;
    cin >> n;
    int m = n-1;
    vector<int> vs(n+1);
    fill_n(paths, n+1, vector<int>());
    fill_n(adj, n+1, vector<pair<int,int>>());
    fill_n(processed, n+1, false);
    for(int i=1; i<=n; ++i) cin >> vs[i];
    for(int i=0; i<m; ++i){
      int a, b;
      cin >> a >> b;
      adj[a].push_back({b,value[b]});
      adj[b].push_back({a,value[a]});
    }

    for(int i=1; i<=n; ++i) value[i] = vs[i];
    dfs(1,0);
    
    cout << "Case #" << k+1 << ": " << "answer goes here" << endl;
  }
  return 0;
}


