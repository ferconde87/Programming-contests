#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

	int n;
	string s;
	cin >> n >> s;
	map<string, int> m;
	char l = s[0];
	char r = s[1];
	char temp;
	
	string cur;
	int num = 0;
	int max = 0;
	string ans;
	for(int i = 0; i < s.size(); i++){
		cur = s.substr(i,2);
		auto it = m.find(cur);
		if(it != m.end()){
			it->second++;
			num = it->second;
		}else{
			m[cur] = 1;
			num = 1;
		}
		if(num > max){
			max = num;
			ans = cur;
		}
	}
	
	cout << ans << endl;

	return 0;
}