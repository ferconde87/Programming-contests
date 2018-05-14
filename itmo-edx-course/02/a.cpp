#include <fstream>
#include <math.h>

using namespace std;

int main(){
    long long a, b;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> a >> b;
    long long b2 = b * b;//pow(b,2) => wrong answer
    fout << (a + b2);
    
    return 0;

}