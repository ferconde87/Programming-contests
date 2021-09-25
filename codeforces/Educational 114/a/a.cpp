#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

	int t; cin >> t;

	while(t--){
		int n;
		cin >> n;
		for(int k=0; k<n; ++k){
			string s;
			for(int i=1; i<=n-k; ++i)
				s.push_back('(');
			for(int i=1; i<=n-k; ++i)
				s.push_back(')');
			for(int j=0; j<k; ++j)
				s.append("()");
			cout << s << "\n";
		}
	}
	
	return 0;
}
