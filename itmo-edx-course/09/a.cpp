#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int LIMIT = 300*60;//timespan in seconds of a ACM ICPC Final
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    int a[15];//int a[n]; => no le gusta que use una variable que es asignada por >>
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a+n);
    int time = LIMIT;
    int ans = 0;
    for(int i = 0; i < n && time > 0; i++){
        time -= a[i];
        ans++;
    }
    if(time < 0) ans--;
    fout << ans;

}