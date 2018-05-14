#include <iostream>
#include <fstream>	

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int a, b;
    in >> a >> b;
    out << (a+b);
	
	return 0;
}