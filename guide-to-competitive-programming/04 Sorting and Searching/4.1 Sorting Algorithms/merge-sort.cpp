#include <bits/stdc++.h>

using namespace std;


void merge(vector<int> & v, vector<int> & w, int lstart, int lend, int rstart, int rend){
	int i = lstart;
	int j = rstart;
	int k = lstart;
	
	while(i <= lend && j <= rend){
		if (v[i] < v[j]) w[k++] = v[i++];
	    else w[k++] = v[j++];
	}
	
	while(i <= lend)    w[k++] = v[i++];

	while(j <= rend)    w[k++] = v[j++];
	
	for(int i = lstart; i <= rend; i++) v[i] = w[i];
}

void mergeSort(vector<int> &v, vector<int> & w, int start, int end){
	if(start >= end) return;
	int mid = (start + end) / 2;
	mergeSort(v, w, start, mid);
	mergeSort(v, w, mid+1, end);
	merge(v, w, start, mid, mid+1, end);
}

void mergeSort(vector<int> & v){
	int n = v.size();
	vector<int> w(n);
	mergeSort(v, w, 0, n-1);
}

void print(vector<int> & v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
    vector<int> v = {1,3,8,2,9,2,5,6};
    mergeSort(v);
    print(v);
    v = {-1,3,-8,2,9,2,5};
    mergeSort(v);
    print(v);
    return 0;
}