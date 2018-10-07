#include <bits/stdc++.h>

using namespace std;

bool Not_one(string N) {
    int sz = N.size();
    if(sz > 1)
            return 1;
    if(N[0] != '1')
            return 1;
    return 0;
}

bool is_Eve(string N) {
    int data = (N[N.size() - 1] - '0') & 1;// data := 1 => odd , 0 => even
    if(data)
            return 0;
    return 1;
}

string Divide(string N, int data) {
    reverse(N.begin(), N.end());
    long long base = 10;
    string temp = "";
    for(int i = (int)N.size() - 1, rem = 0; i >= 0; --i) {
        long long Cur = (N[i] - '0') + rem * base;
        int val = Cur / data;
        rem = Cur % data;
        temp += (val + '0');
    }

    //erase 0's at the beginning    
    while(temp.size() && !(temp[0] - '0'))
            temp.erase(temp.begin());
    

    return temp;
}

int power(string N) {
    
    int sz = N.size();
    if(sz == 1) {
        if(N[0] == '2' || N[0] == '4' || N[0] == '8')
                return 1;
        return 0;
    } else {
        while(Not_one(N) && is_Eve(N)) {
            N = Divide(N, 2);
            if(N.size() == 1 &&  N[0] == '1')
                    break;
        }
        if(Not_one(N))
                return 0;
        return 1;
    }
}


int main(){
    
    cout << power("2048") << endl;

    return 0;
}