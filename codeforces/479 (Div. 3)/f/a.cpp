#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	map<int, int> dp;//using unordered_map give us LTE :P
	int a[n];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int len = 0;
	int last = 0;
	for(int i = 1; i <= n; i++){
		int x = a[i];
		dp[x] = dp[x-1] + 1;//if dp[x-1]==0 , dp[x-1] = 0;
		if(dp[x] > len){
			len = dp[x];
			last = x;
		}
	}

	int ans[len];
	int j = len-1;
	for(int i = n; i >= 1; i--){
		if(a[i]==last){
			ans[j--] = i;
			last--;
		}
	}

	printf("%d\n", len);
	for(int i = 0; i < len; i++){
		printf("%d ", ans[i]);
	}
	cout << endl;
	
	return 0;
}