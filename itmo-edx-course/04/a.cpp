#include <fstream>
#include <algorithm>

using namespace std;

// int solve(){
//     int n;
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");
//     fin >> n;
//     long long a[100];
//     long long b[100];
//     for(int i = 0; i < n; i++) fin >> a[i];
//     for(int i = 0; i < n; i++) fin >> b[i];
//     sort(a, a+n);
//     sort(b, b+n);
//     int i = n-1;
//     int j = n-1;
//     long long result = 0;
//     for(int k = 0; k < n-1; k++){
//         if(a[i] > b[j]){
//             result += a[i--];
//         }else{
//             result += b[j--];
//         }
//     }
//     //nos aseguramos que haya al menos un elemento de cada array
//     if(a[0]>b[n-1]) result += b[n-1];
//     else if(b[0] > a[n-1]) result += a[n-1];
//     else result += max(a[i],b[j]);
    
//     fout << result;
// }

int main(){
    int n;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    long long a[100];
    long long b[100];
    for(int i = 0; i < n; i++) fin >> a[i];
    for(int i = 0; i < n; i++) fin >> b[i];
    long long result = 0;
    int diff = 0;
    int minDiff = a[0]+b[0];
    int aUsed = false;
    int bUsed = false;
    for(int i = 0; i < n; i++){
        diff = a[i] - b[i];
        if(diff >= 0){
            result += a[i];
            minDiff = min(minDiff, diff);
            aUsed = true;
        }else{
            result += b[i];
            minDiff = min(minDiff, abs(diff));
            bUsed = true;
        }
    }
    if(!(aUsed && bUsed)){
        result -= minDiff;
    }
    
    fout << result;
    
    return 0;
}