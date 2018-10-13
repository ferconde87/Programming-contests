#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;



int main(){
	int q; cin >> q;
	vector<int> l, r;
	for(int i = 0; i < q; i++){
		char c; cin >> c;
		int x; cin >> x;
		if(c == 'L') l.push_back(x);
		else if(c == 'R') r.push_back(x);
		else{
            int ls = l.size();
            int rs = r.size();
            int counter = 0;
            for(int j = ls-1;  j >= 0; j--){
                if(l[j] == x) break;
                counter++;
            }
            if(counter == ls){
                //not found in l
                counter = 0;
                for(int j = rs-1; j >= 0; j--){
                    if(r[j] == x) break;
                    counter++;
                }
                cout << min(counter, ls+(rs-counter)) << endl;
            }else{
                //found in l
                cout << min(counter, rs+(ls-counter)) << endl;
            }
        }
	}

    
	
	return 0;
}