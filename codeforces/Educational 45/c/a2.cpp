#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    fout << n << "\n";
    for(int i = 0; i < n; i++){
        fout << "()\n";
    }
    return 0;
}