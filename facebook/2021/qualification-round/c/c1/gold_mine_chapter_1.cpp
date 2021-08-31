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
  value[s]+=value[prev];
  processed[s] = true;
  if(value[s] > max_value){
    max_value = value[s];
    max_cave = s;
  }
  for(auto u : adj[s]){
    if (u.first == prev) continue;
    if(processed[u.first]) continue;
    dfs(u.first, s);
  }  
}

void dfs2(int s, int prev){
  value[s]+=value[prev];
  paths[s] = paths[prev];
  if(paths[s].size()<2)
    paths[s].push_back(s);
  processed[s] = true;
  if(value[s] > max_value){
    max_value = value[s];
    max_cave = s;
  }
  for(auto u : adj[s]){
    if (u.first == prev) continue;
    if(processed[u.first]) continue;
    dfs2(u.first, s);
  }
}

int main(){
  freopen("gold_mine_chapter_1_input.txt", "r", stdin);
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
    dfs2(1,0);
    int ans = max_value;
    for(int i=1; i<=n; ++i) value[i] = vs[i];
    if(paths[max_cave].size()>1){
      value[paths[max_cave][1]] = -max_value;
    }
    value[1] = 0;
    fill_n(processed, n+1, false);
    max_value = 0;
    dfs(1,0);
    ans += max_value;
    max_value = 0;
    cout << "Case #" << k+1 << ": " << ans << endl;
  }
  return 0;
}


