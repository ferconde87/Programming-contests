#include <bits/stdc++.h>

using namespace std;

const int N = 50;
string m[N];

int min_gt_0(vector<int> &v){
  int ans = N+1;
  for(int x : v){
    if(x < 0) continue;
    ans = min(x, ans);
  }
  return ans;
}

int main(){
  freopen("xs_and_os_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for(int k=0; k<t; ++k){
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; ++i){
      getline(cin, m[i]);
    }

    vector<int> rem_in_row(n);
    for(int i=0; i<n; ++i){
      int cur=0;
      for(int j=0; j<n; ++j){
        if(m[i][j]=='.') cur++;
        else if(m[i][j]=='O'){
          cur=-1;
          break;
        }
      }
      rem_in_row[i]=cur;
    }

    vector<int> rem_in_col(n);
    for(int j=0; j<n; ++j){
      int cur=0;
      for(int i=0; i<n; ++i){
        if(m[i][j]=='.') cur++;
        else if(m[i][j]=='O'){
          cur=-1;
          break;
        }
      }
      rem_in_col[j]=cur;
    }

    int min_in_row = min_gt_0(rem_in_row);
    int min_in_col = min_gt_0(rem_in_col);
    int min_total = min(min_in_row, min_in_col);

    cout << "Case #" << k+1 << ": "; 
    if(min_total == N+1){
      cout << "Impossible" << endl;
    }else{
      set<vector<pair<int, int>>> ans;
      for(int i=0; i<n; ++i){
        vector<pair<int,int>> current;
        if(rem_in_row[i]==min_total){
          for(int j=0; j<n; ++j){
            if(m[i][j]=='.')
              current.push_back({i,j});
          }
        }
        if(current.size() > 0) ans.insert(current);
      }

      for(int j=0; j<n; ++j){
        vector<pair<int,int>> current;
        if(rem_in_col[j]==min_total){
          for(int i=0; i<n; ++i){
            if(m[i][j]=='.')
              current.push_back({i,j});
          }
        }
        if(current.size() > 0) ans.insert(current);
      }
      
      cout << min_total << " " << ans.size() << endl;
    }

  }
  return 0;
}
