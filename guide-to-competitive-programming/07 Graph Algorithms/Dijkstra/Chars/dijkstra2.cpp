#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=1; k<=t; ++k){
    int n, m;
    cin >> n >> m;
    unordered_map<char, int> keys;
    int index = 1;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; ++i){
      char a, b;
      int w;
      cin >> a >> b >> w;
      int index_a = keys[a];
      if(index_a == 0){
        index_a = index++;
        keys[a] = index_a;
      }
      int index_b = keys[b];
      if(index_b == 0){
        index_b = index++;
        keys[b] = index_b;
      }
      adj[index_a].push_back({index_b,w});
      adj[index_b].push_back({index_a,w});
    }
    priority_queue<pair<int,int>> q;
    vector<int> distance(n+1, INT_MAX);
    vector<bool> processed(n+1, false);
    int start = 1;
    distance[start] = 0;
    q.push({0,start});
    while(!q.empty()){
      int a = q.top().second; q.pop();
      if(processed[a]) continue;
      processed[a] = true;
      for(auto u : adj[a]){
        int b = u.first, w = u.second;
        if(distance[a] + w < distance[b]){
          distance[b] = distance[a] + w;
          q.push({-distance[b], b});
        }
      }
    }
    for(int i=1; i<=n; ++i){
      cout << distance[i] << " ";
    }
    cout << endl;
  }


  
}
