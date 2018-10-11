#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

	int t; cin >> t;

	for(int i = 0; i < t; i++){
		long long s, a, b, c;
		cin >> s >> a >> b >> c;
		long long total = s / c;
		long long promo = total / a;
		cout << promo*b + total << endl;
	}
	
	return 0;
}