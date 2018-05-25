#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

//This was the solution that I submitted 
int solve(){
	int MAX = (int)pow(10, 9);
	int n, k;
	cin >> n >> k;
	int a[n+1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a+1, a+n+1);

    if(k == 0) {
        if(a[1] == 1) return -1;
        else return 1;
    }

	if(k == n) return a[k];
	
	int x = a[k];

	if(x == a[k+1]) return -1;

	return x;
}

int main(){

	cout << solve() << endl;
	
	return 0;
}