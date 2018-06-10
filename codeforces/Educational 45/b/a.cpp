#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int solve(){
	long long n, k;
	cin >> n  >> k;
	long long a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	sort(a, a+n);

	int ans = 0;
	int j = 1;
	for(int i = 1; i < n; i++){
		if(a[i]==a[i-1]) j++;
		else{
			for(int l = 1; l <= j; l++){
				if(a[i]<=a[i-l]+k) ans++;
			}
			j = 1;
		}
	}

	return n-ans;
}

int main(){

	cout << solve() << endl;

	return 0;
}