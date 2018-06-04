#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;


//WA (leer)
//como lo quería hacer originalmente (con countingSort)
//pero de esta forma se pierde la info de los índice a extraer

int main(){

	int k; cin >> k;
    int const max_len = 20000+1;
	bitset<20000+1> bs[k+1];
    int sum[k];
	int len = 0;
    int offset = 10000;

	for(int t = 1; t <= k; t++){
		int n; cin >> n;
		int count = 0;
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			count += x;
			bs[t].set(offset+x);
            cout << offset+x;
		}
        cout << endl;
        sum[t] = count;
	}

    bool possible = false;
    for(int i = 1; i <= k && !possible; i++){
        for(int j = i+1; j <= k && ! possible; j++){
            int diff = sum[i] - sum[j];
            int offset_j = (diff < 0) ? diff*-1 : 0;
            int offset_i = (diff < 0) ? 0 : diff;
            for(int l = 0; l < max_len && ! possible; l++){
                if(bs[i][l+offset_i] && bs[j][l+offset_j]){
                    cout << "YES" << endl;
                    cout << i << " (?)" << endl;
                    cout << j << " (?)" << endl;
                    possible = true;
                }
            }
        }
    }

	if(!possible){
		cout << "NO" << endl;
	}

	return 0;
}