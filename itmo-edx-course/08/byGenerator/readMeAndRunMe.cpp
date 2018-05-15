/*
 * Warning, this is a solution GENERATOR, not the actual solution!
 * First run it, then submit its output!
 */
#include <stdio.h>

int divcount[10000001];

int main() {
    int n = 10000000, i, j;
    int best_value = -1, best_count = 0, num_count = 0;

    for (i = 2; i <= n; ++i) {
        divcount[i] += 2;
        for (j = 2 * i; j <= n; j += i) {
            ++divcount[j];
        }
    }

    printf("#include <stdio.h>\n"
           "int hcn[] = { 0");

    for (i = 2; i <= n; ++i) {
        if (best_count < divcount[i]) {
            best_count = divcount[i];
            best_value = i;
            printf(", %d", i);
            ++num_count;
        }
    }
    printf("};\n");
    printf("int num_count = %d;\n", num_count);
    printf("int main() {\n"
           "    int n, x, i;\n"
           "    freopen(\"input.txt\", \"r\", stdin);\n"
           "    freopen(\"output.txt\", \"w\", stdout);\n"
           "    scanf(\"%%d\", &n);\n"
           "    for (i = 1; i <= num_count; ++i) {\n"
           "        if (hcn[i] <= n) x = hcn[i];\n"
           "    }\n"
           "    printf(\"%%d\\n\", n - x + 1);\n"
           "    return 0;\n"
           "}\n");
    return 0;
}