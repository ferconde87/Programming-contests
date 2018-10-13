#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){
	int q; cin >> q;
	vector<int> v;
	for(int i = 0; i < q; i++){
		char c; cin >> c;
		int x; cin >> x;
		if(c == 'L') v.insert(v.begin(), x);
		else if(c == 'R') v.push_back(x);
		else{
			int n = v.size();
			int j = 0;
			for(; j < n; j++){
				if(v[j] == x){
					cout << min(j,n-1-j) << endl;
				}
			}
		}
	}

    
	
	return 0;
}