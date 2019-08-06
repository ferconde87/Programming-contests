#import <iostream>
#import <string>

using namespace std;

int counter = 0; 

int decodeVariationsHelper(const string& S, int index, int size){
  if(index == size){
    counter++;
    return counter;
  } 
  char current = S[index];
  
  if(current == '0') return counter;
  
  if(current == '1' && index+1 < size){
    decodeVariationsHelper(S, index+2, size);
  }
  else if(current == '2' && index+1 < size){
    char next = S[index+1];
    if(next <= '6'){
      decodeVariationsHelper(S, index+2, size);
    }
  }
  return decodeVariationsHelper(S, index+1, size);
}

int decodeVariations(const string& S){
  counter = 0;
  int n = S.size();
  cout << "counter = " << counter << endl;
	return decodeVariationsHelper(S, 0, n);
}

int main() 
{
	return 0;
}

