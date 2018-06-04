#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int main(){

	int k; cin >> k;
	vector<tuple<int, int, int> > tuple_v;

	int len = 0;
	for(int t = 1; t <= k; t++){
		int n; cin >> n;
		int a[n+1];
		int sum = 0;
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			sum += x;
			a[i] = x;
		}
		for(int i = 1; i <= n; i++){
			tuple_v.push_back(make_tuple(sum-a[i], t, i));
		}
		len+= n;
	}
	bool possible = false;
	sort(tuple_v.begin(), tuple_v.end());
	for(int i = 1; i <= len; i++){
		// cout << get<0>(tuple_v[i]) << " " << get<1>(tuple_v[i]) << " " << get<2>(tuple_v[i]) << " " <<  endl; 
		if(get<0>(tuple_v[i]) == get<0>(tuple_v[i+1]) && get<1>(tuple_v[i]) != get<1>(tuple_v[i+1])){
			// cout << get<0>(tuple_v[i+1]) << " " << get<1>(tuple_v[i+1]) << " " << get<2>(tuple_v[i+1]) << " " <<  endl; 
			cout << "YES" << endl;
			cout << get<1>(tuple_v[i]) << " " << get<2>(tuple_v[i]) << endl;
			cout << get<1>(tuple_v[i+1]) << " " << get<2>(tuple_v[i+1]) << endl;
			possible = true;
			break;
		}
	}
	if(!possible){
		cout << "NO" << endl;
	}

	return 0;
}