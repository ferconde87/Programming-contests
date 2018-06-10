#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

long long solve(){
	long long n, m, a, b;
	cin >> n >> m >> a >> b;

	long long r = n % m;
	if(r==0) return 0;
	long long newc = (m-r)*a;
	long long delc = r*b;
	return min(newc,delc);
}

int main(){

	cout << solve() << endl;	
	return 0;
}