#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// void solve(){
//         double a[3];
//     double b[3];
//     double c[3];
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");
//     for(int i = 0; i < 3; i++)
//         fin >> a[i] >> b[i] >> c[i];
//     for(int i = 0; i < 3; i++){
//         a[i] *= a[i]; 
//         b[i] *= b[i]; 
//         c[i] *= c[i]; 
//     }
    
//     double result1 = a[0] + b[1] + c[2];
//     double result2 = a[0] + b[2] + c[1];
//     double result3 = a[1] + b[0] + c[2];
//     double result4 = a[2] + b[0] + c[1];
//     double result5 = a[1] + b[2] + c[0];
//     double result6 = a[2] + b[1] + c[0];
//     result1 = sqrt(result1);
//     result2 = sqrt(result2);
//     result3 = sqrt(result3);
//     result4 = sqrt(result4);
//     result5 = sqrt(result5);
//     result6 = sqrt(result6);
//     double max1 = max(result1, result2);
//     double max2 = max(result3, result4);
//     double max3 = max(result5, result6);
//     max1 = max(max1, max2);
//     max1 = max(max1, max3);

//     fout << setprecision(10) << max1 << endl;
// }

int main(){
    double a[3];
    double b[3];
    double c[3];
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    for(int i = 0; i < 3; i++)
        fin >> a[i] >> b[i] >> c[i];
    double max1 = max((a[0]*a[0] + b[1]*b[1] + c[2]*c[2]), (a[0]*a[0] + b[2]*b[2] + c[1]*c[1]));
    double max2 = max((a[1]*a[1] + b[0]*b[0] + c[2]*c[2]), (a[2]*a[2] + b[0]*b[0] + c[1]*c[1]));
    double max3 = max((a[1]*a[1] + b[2]*b[2] + c[0]*c[0]), (a[2]*a[2] + b[1]*b[1] + c[0]*c[0]));
    max1 = max(max1, max2);
    max1 = max(max1, max3);

    fout << setprecision(10) << sqrt(max1) << endl;

    return 0;
}