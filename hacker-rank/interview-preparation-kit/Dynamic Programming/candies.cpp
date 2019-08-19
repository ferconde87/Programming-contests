#include <bits/stdc++.h>

using namespace std;

void print(vector<int> & v){
    for(int x : v) cout << x << " "; cout << endl;
}

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    if(n == 1) return 1;
    vector<int> counter(n,0);
    counter[0] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            counter[i] = counter[i-1]+1;
        }else{ 
            counter[i] = 1;
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(arr[i] < arr[i-1]){
            counter[i-1] = max(counter[i-1], counter[i]+1); 
        }
    }
    return accumulate(counter.begin(), counter.end(), (long)0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

