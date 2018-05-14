#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    double a, b, c;
    fin >> a >> b >> c;
    fout << setprecision(8) << (a + b + c) / 6;
    return 0;
}