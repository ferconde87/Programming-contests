#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

long long solve(){
	int n; cin >> n;
	map<int, long long> m;
	long long ans = 0;
	set<int> s;
	for(int i = 0; i < n; i++){
		string xs; cin >> xs;
		int x = 0;
		int min_x = 0;
		for(auto c : xs){
			if(c == '(') x++;
			else x--;
			if(x < min_x) min_x = x;

		}
		if(min_x < 0 && min_x != x) continue;
		
		if(x>0) s.insert(x);
		auto it = m.find(x);
		if(it != m.end()){
			m[x]++;
		}else{
			m[x]=1;
		}
	}

	//0's;
	auto it = m.find(0);
	if(it != m.end()){
		ans = it->second * it->second;
	}

	for(auto x : s){
		auto itl = m.find(x);//in
		auto itr = m.find(x*(-1));//in?
		if(itr != m.end()){
			ans += itl->second*1LL*itr->second;
		}		
	}

	return ans;
}

int main(){

    cout << solve() << endl;
	
	return 0;
}