#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3000000;

double average_distance(const vector<int> &permutation) {
    double distance_sum = 0;

    for (int i = 0; i < N; i++)
        distance_sum += abs(permutation[i] - i);

    return distance_sum / N;
}

int main() {
    vector<int> permutation(N);

    for (int i = 0; i < N; i++)
        permutation[i] = i;

    random_shuffle(permutation.begin(), permutation.end());
    cout << average_distance(permutation) << '\n';
    //999779
}
