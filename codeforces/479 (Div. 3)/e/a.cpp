#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;
const int N = 2*100000+1;
vector<int> graph[N];
bool seen[N];
vector<int> component;

void dfs(int a) {
	seen[a] = true;
	component.push_back(a);
	for (auto b : graph[a])
		if (!seen[b])
			dfs(b);
}


int main(){

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!seen[i]){
			dfs(i);
			bool all2edges = true;
			for(auto b : component){
				if(graph[b].size()!=2){
					all2edges = false; break;
				}
			}
			if(all2edges) ans++;
			component.clear();
		}
	}
	
	cout << ans << endl;	
	
	return 0;
}