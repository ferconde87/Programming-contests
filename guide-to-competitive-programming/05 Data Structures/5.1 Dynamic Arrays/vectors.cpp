#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &v){
    for (auto x : v) cout << x << " "; cout << "\n";
}

int main(){

    const int n = 10;
    int array[n];//fixed-size array

    //1. Vectors
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]
    cout << v[0] << "\n"; // 3
    cout << v[1] << "\n"; // 2
    cout << v[2] << "\n"; // 5

    vector<int> w = {2,4,2,5,1};

    vector<int> a(8); // size 8, initial value 0
    vector<int> b(8,2); // size 8, initial value 2


    for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << "\n";

    // A shorter way to iterate through a vector is as follows
    for (auto x : v) {
        cout << x << "\n";
    }
    cout << "\n";
    v = {2,4,2,5,1};
    cout << v.back() << "\n"; // 1
    v.pop_back();
    cout << v.back() << "\n\n"; // 5

    //2. Iterators ans Ranges
    v = { 5, 2, 3, 1, 2, 5, 7, 1 };     print(v);
    sort(v.begin(),v.end());            print(v);       
    reverse(v.begin(),v.end());         print(v);
    random_shuffle(v.begin(),v.end());  print(v);

    //an iterator points can be accessed using the * syntax
    cout << *v.begin() << "\n\n";


    v = {2,3,3,5,7,8,8,8};
    auto it_a = lower_bound(v.begin(),v.end(),5);//iterator to the first element in a sorted range whose value is at least x
    auto it_b = upper_bound(v.begin(),v.end(),5);//iterator to the first element whose value is larger than x
    // If there is no such element, the functions return an iterator to the element after the
    // last element in the range =>> return v.end()
    cout << *it_a << " " << *it_b << "\n"; // 5 7

    auto exampleNotFound = upper_bound(v.begin(), v.end(), 8);
    if(exampleNotFound == v.end()) cout << "Element larger than 8 not found in v" << "\n\n";

    //3. Other Structures
    // The C++ standard library contains a large number of useful functions that are
    // worth exploring. For example, the following code creates a vector that contains the
    // unique elements of the original vector in a sorted order:
    v = {4,3,4,5,2,1,4,5,6,7,5,3,2,1,1,2,3,4,4,5,6,3,10,-4};    print(v);
    sort(v.begin(),v.end());                                    print(v);
    v.erase(unique(v.begin(),v.end()),v.end());                 print(v);

    return 0;
}