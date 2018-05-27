#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

void printBits(int num){
	for(int i = 31; i >= 0; i--){
		cout << getBit(num, i);
	}
	cout << endl;	
}

void printBitsLL(long long num){
	for(int i = 63; i >= 0; i--){
		cout << ((num & (1LL << i)) != 0);
	}
	cout << endl;	
}

//puts 1 in the ith position of int num
int setBit(int num, int i){
	return num | (1 << i);
}

//puts 0 in the ith position of int num
int clearBit(int num, int i){
	return num & ~(1 << i);
}

//clear bits from most significant bit to ith
int clearBitsMSBthroughtI(int num, int i){
	int mask = (1 << i) - 1;
	return num & mask;
}
//clear bits from ith to 0
int clearBitsIThrought0(int num, int i){
	int mask = -1 << (i + 1);
	return num &  mask;
}


bool isDivisibleByPower2OfK(int x, int k) {

    int power = pow(2, k);
    int mask = power - 1;
    cout << "power: \t";printBits(power);
    cout << "mask: \t";printBits(mask);
    cout << "x: \t";printBits(x);

    return ((x & mask)==0);
}


int main(){
    cout << isDivisibleByPower2OfK(2000.0, 5.0) << endl;//false 0
    int x = 32*17*3;
    cout << isDivisibleByPower2OfK(x, 5) << endl;//true 1
    cout << endl;

    // Additional Functions The g++ compiler also provides the following functions for
    // counting bits:
    // ••••__builtin_clz(x): the number of zeros at the beginning of the bit represen-
    // tation
    // __builtin_ctz(x): the number of zeros at the end of the bit representation
    // __builtin_popcount(x): the number of ones in the bit representation
    // __builtin_parity(x): the parity (even or odd) of the number of ones in the
    // bit representation
    x = 5328; // 00000000000000000001010011010000
    cout <<  __builtin_clz(x) << "\n"; // 19
    cout << __builtin_ctz(x) << "\n"; // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n"; // 1
    cout << endl;
    unsigned long long y = 12345678910111213141516; 
    //y in base-2 = 0100001010110110010101101000100100110010100010111011111000001100
    printBitsLL(y);
    cout <<  __builtin_clzll(y) << "\n"; // 1
    cout << __builtin_ctzll(y) << "\n"; // 2
    cout << __builtin_popcountll(y) << "\n"; // 29
    cout << __builtin_parityll(y) << "\n"; // 1
    return 0;
}