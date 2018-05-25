#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

unsigned int n;
vector<unsigned long long> result;
unordered_set<unsigned long long> s;

void next(unsigned long long e){
	unsigned long long x2 = e*2;
	auto it = s.find(x2);
	if (it != s.end()){
		result.push_back(x2);
		next(x2);
	}
	if(!(e%3)){// (e mod 3) == 0
		unsigned long long div3 = e/3;
		auto it = s.find(div3);
		if(it != s.end()){
			result.push_back(div3);
			next(div3);
		}else{
			return;
		}
	}else{
		return;
	}
}


void solve(){
	for(auto e : s){
		result.push_back(e);
		next(e);
		if(result.size()==n)
			return;
		else
			result.clear();
	}
}


int main(){
	
	cin >> n;

	for(unsigned int i = 0; i < n; i++){
		unsigned long long x;cin >> x;
		s.insert(x);
	}

	solve(); 

	for(unsigned int i = 0; i < n; i++){
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
}