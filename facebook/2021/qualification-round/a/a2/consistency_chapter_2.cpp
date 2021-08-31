#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int main(){
  freopen("consistency_chapter_2_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  cin.ignore();
  for(int k=1; k<=t; ++k){
    int index = 1;
    string s;
    getline(cin, s);
    unordered_map<char, int> keys;
    vector<int> occurrences(26,0);
    vector<char> chars({'*'});//we start from index 1
    for(char c : s){
      occurrences[c-'A']++;
    }
  
    int m;
    cin >> m;
    cin.ignore();
    vector<vector<pair<int,int>>> adj(N);
    for(int i=0; i<m; ++i){
      string e;
      getline(cin, e);
      char a = e[0];
      char b = e[1];
      int index_a = keys[a];
      if(index_a == 0){
        index_a = index++;
        keys[a] = index_a;
        chars.push_back(a);
      }
      int index_b = keys[b];
      if(index_b == 0){
        index_b = index++;
        keys[b] = index_b;
        chars.push_back(b);
      }
      
      adj[index_b].push_back({index_a,1});
    }

    bool consistent = true;
    for(int i=1; i<s.size(); ++i)
      if(s[i-1]!=s[i])
        consistent = false;

    if(consistent){
      cout << "Case #" << k << ": " << 0 << endl;
      continue;
    }

    bool ok = true;
    for(int i=0; i<26; ++i){
      if(occurrences[i] > 0){
        char c = (char)('A'+i);
        if(keys.find(c)==keys.end()){
          ok = false;
          break;
        }
      }
    }

    if(!ok){
      cout << "Case #" << k << ": " << -1 << endl;
      continue;
    } 
      
    int ans = INT_MAX;
    for(int start = 1; start < index; ++start){
      priority_queue<pair<int,int>> q;
      vector<int> distance(N, INT_MAX);
      vector<bool> processed(N, false);
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
      int dist = 0;
      for(int i=1; i<index; ++i){
        if(distance[i]==INT_MAX && occurrences[chars[i]-'A']>0){
          dist = INT_MAX;
          break;
        }
        dist+= occurrences[chars[i]-'A']*distance[i];
      }
      ans = min(ans, dist);

    }
    if(m==0) ans=0;
    if(ans == INT_MAX) ans=-1;
    cout << "Case #" << k << ": " << ans << endl;
  }
  
  return 0;
}
