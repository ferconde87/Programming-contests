#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){
	int t; cin >> t;

	while(t--){
		int v[3];
		int m;
		cin >> v[0] >> v[1] >> v[2] >> m;
		sort(v,v+3);
		int a = v[0];
		int b = v[1];
		int c = v[2];
		if(c - 1 - (a+b) <= m && m <= a + b + c - 3) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
