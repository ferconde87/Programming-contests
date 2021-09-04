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
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; ++i){
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].push_back({b,w});
      adj[b].push_back({a,w});
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
      for(int i=1; i<=n; ++i){
        cout << distance[i] << " ";
      }
      cout << endl;

    }
    cout << endl;
  }


  
}
