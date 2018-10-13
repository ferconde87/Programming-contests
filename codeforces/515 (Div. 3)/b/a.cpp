#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


int main(){

	int n, r; cin >> n >> r;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	int b[n]; for(int i = 0; i < n; i++) b[i] = 0;
	
	int len = 2*r - 1;

	int ans = 0;
	for(int i = 0; i < n; i++){
		bool ok = false;
		if(a[i] == 1){
			for(int j = max(i-r+1,0); j <= min(i+r-1,n); j++){
				b[j]++;
			}
			ans++;
		}
	}
	// cn(ans)

	// for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;

	int min_e = *min_element(b, b+n);
	if(min_e == 0) cout << -1 << endl;
	else{
		for(int i = 0; i < n; i++){
			// if(b[i] > 1){
			if(a[i] == 1){
				bool u = true;
				// cout << i << " " << min(i+2*r-2,n) << endl;
				// for(int j = i; j <= min(i+2*r-2,n-1); j++){
				// 	cout << b[j] << " ";
				// 	if(b[j] == 1){
				// 		u = false; 
				// 	} 
				// }
				// cout << max(i-r+1,0) << " " << min(i+r-1,n-1) << endl;
				for(int j = max(i-r+1,0); j <= min(i+r-1,n-1); j++){
					// cout << b[j] << " ";
					if(b[j] == 1){
						u = false; 
					} 
				}
				// cout << endl;
				if(u){
					for(int j = max(i-r+1,0); j <= min(i+r-1,n-1); j++) b[j]--;
					// for(int j = i; j <= min(i+2*r-2,n-1); j++) b[j]--;
					// for(int j = i; j <= min(i+2*r-2,n-1); j++) cout << b[j] << " "; cout << endl;

					// cn(i)
					ans--;
				} 
			}
		}
		cout << ans << endl;
	}

	return 0;
}