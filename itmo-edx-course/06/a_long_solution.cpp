#include <fstream>
#include <algorithm>

using namespace std;

double distance(double dx, double dy){
    return sqrt(dx * dx + dy * dy);
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    double a, b, c;
    fin >> a >> b >> c;

    double cos = (b * b + c * c - a * a) / (2.0 * b * c);
    double sin = sqrt(1 - cos * cos);
    double xc = b * cos;
    double yc = b * sin;

    double midXC = c / 2, midYC = 0;
    double midXB = xc / 2, midYB = yc / 2;
    double midXA = (xc + c) / 2, midYA = yc / 2;

    double lenAB = distance(midXA - midXB, midYA - midYB);
    double lenAC = distance(midXA - midXC, midYA - midYC);
    double lenBC = distance(midXB - midXC, midYB - midYC);

    fout << ((lenAB + lenAC + lenBC) / 3);
    
    return 0;
}