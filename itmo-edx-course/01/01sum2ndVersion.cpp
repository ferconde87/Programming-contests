#include <cstdio>

using namespace std;

int main(){
    FILE *in = fopen("input.txt", "rt");
    FILE *out = fopen("output2.txt", "wt");
    int a, b;
    fscanf(in, "%d%d", &a, &b);
    fprintf(out, "%d\n", a + b);
    return 0;
}