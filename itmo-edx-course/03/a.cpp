#include <fstream>

using namespace std;
//Three-bonacci
int main(){
    long long a0, a1, a2, n;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> a0 >> a1 >> a2 >> n;
    long long result;
    if(n==0) result = a0;
    if(n==1) result = a1;
    if(n==2) result = a2;
    for(int i = 3; i <= n; i++){
        result = a2 + a1 - a0;
        a0 = a1;
        a1 = a2;
        a2 = result;
    }
    fout << result;
}