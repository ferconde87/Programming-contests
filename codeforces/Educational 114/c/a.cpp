#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> hs(n);
	ll sum = 0;
	for(int i=0; i<n; ++i){
		cin >> hs[i];
		sum += hs[i];
	}
	sort(hs.begin(), hs.end());
	int m;
	cin >> m;
	for(int i=0; i<m; ++i){
		ll x, y;
		cin >> x >> y;
		auto it = lower_bound(hs.begin(), hs.end(), x);
		ll o = -1;
		ll a = 0;
		if(it == hs.end()){
			it = --hs.end();
			a = *it;
		}else{
			a = *it;
			if(it != hs.begin()) o = *--it;
		}
		ll ans = 0;
		if(x > a) ans = x - a;
		ll b = sum - a;
		if(y > b) ans += (y - b);
		if(o!=-1){
			ll ans2 = 0;
			if(x > o) ans2 = x - o;
			b = sum - o;
			if(y > b) ans2 += (y - b);
			cout << min(ans, ans2) << "\n";	
		}else{
			cout << ans << "\n";
		}
	}
	return 0;
}
