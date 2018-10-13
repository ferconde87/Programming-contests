#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

	int t; cin >> t;
	for(int i = 0; i < t; i++){
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		int lanterns = L / v;
		// cn(lanterns)
		int ll = (l - 1) / v;
		// cn(ll)
		int rr = r / v;
		// cn(rr)
		cout << lanterns - rr + ll << endl;
	}
	return 0;
}