#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;
#define xn(x) cout << #x << " = ";

//prints 10 less significative bits
void printBits(int num){
    for(int i = 10; i >= 0; i--){
		cout << ((num & (1 << i))!=0);
	}
	cout << endl;	
}


int set_union(int x, int y){
    return x | y;
}

int set_intersection(int x, int y){
    return x & y;
}

int set_complement(int x){
    return ~x;
}

int set_difference(int x, int y){
    return x & (~y);
}

int main(){

    // The following code declares an int variable x that can contain a subset of
    // {0, 1, 2, . . . , 31}. After this, the code adds the elements 1, 3, 4, and 8 to the set
    // and prints the size of the set
    int x = 0;
    x |= (1<<1);//this add 1 to the set x ... x = {1}
    x |= (1<<3);// x = {1,3}
    x |= (1<<4);// x = {1,3,4}
    x |= (1<<8);// x = {1,3,4,8}
    // __builtin_popcount(x) counts the 1's in x ... ie, the amount of element in the set x
    cout << __builtin_popcount(x) << "\n"; // 4
    // Then, the following code prints all elements that belong to the set:
    for (int i = 0; i < 32; i++) {
        if (x&(1<<i)) cout << i << " ";
    }
    cout << "\n";// output: 1 3 4 8


    //SET OPERATIONS
    // x = {1,3,4,8}
    xn(x)printBits(x);
    int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);// y = {1,6,8,9}
    xn(y)printBits(y);
    int z = x|y;// z = y = {1,3,4,6,8,9}
    xn(z)printBits(z);
    cout << __builtin_popcount(z) << "\n"; // 6

    int a = 0;
    a |= (1<<1);
    a |= (1<<2);
    int b = 0;
    b |= (1<<1);
    b |= (1<<3);
    xn(a)printBits(a);
    xn(b)printBits(b);
    int a_union_b = set_union(a,b);
    xn(a_union_b)printBits(a_union_b);
    int a_intersection_b = set_intersection(a,b);
    xn(a_intersection_b)printBits(a_intersection_b);
    int a_complement = set_complement(a);
    xn(a_complement)printBits(a_complement);
    int a_difference_b = set_difference(a,b);
    xn(a_difference_b)printBits(a_difference_b);
    
    // The following code goes through the subsets of {0, 1, . . . , n − 1}:
    int n = 4;
    for (int b = 0; b < (1<<n); b++) {
        // process subset b
        printBits(b);
    }
    cout << endl;
    
    // Then, the following code goes through the subsets with exactly k elements:
    n = 8;
    int k = 4;
    for (int b = 0; b < (1<<n); b++) {
        if (__builtin_popcount(b) == k) {
        // process subset b
        printBits(b);
        }
    }
    cout << endl;

    //Finally, the following code goes through the subsets of a set x:
    xn(x)printBits(x);
    b = 0;
    do {
        // process subset b
        printBits(b);
    } while (b=(b-x)&x);

    //C++ Bitsets


    return 0;
}