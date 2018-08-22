#include <bits/stdc++.h>

using namespace std;

bool isUnique(string s){
    unordered_set<char> set;
    for(char c : s)
        if(set.find(c)!=set.end()) return false;
        else set.insert(c);
    return true;
}

bool isUnique2(string s){
    sort(s.begin(), s.end());
    int n = s.size();
    for(int i = 0; i < n-1; i++)
        if(s[i]==s[i+1]) return false;
    return true;
}

//assuming only lowercase-english characters
bool isUnique3(string s){
    bitset<26> bs;
    for(char c : s){
        if(bs[c-'a']) return false;
        else bs.set(c-'a');
    }
    return true;
}

int main(){

    string s1 = "hola";//distintos
    string s2 = "habiaunavez";//un repetido
    string s3 = "abcdefghijk";//todos distintos
    string s4 = "abcdefeghijk";//repetido en el medio
    string s5 = "abcdefeghijka";//repetido al final
    string s6 = "aaaa";//todos iguales

    assert(isUnique(s1));
    assert(!isUnique(s2));
    assert(isUnique(s3));
    assert(!isUnique(s4));
    assert(!isUnique(s5));
    assert(!isUnique(s6));

    assert(isUnique2(s1));
    assert(!isUnique2(s2));
    assert(isUnique2(s3));
    assert(!isUnique2(s4));
    assert(!isUnique2(s5));
    assert(!isUnique2(s6));

    assert(isUnique3(s1));
    assert(!isUnique3(s2));
    assert(isUnique3(s3));
    assert(!isUnique3(s4));
    assert(!isUnique3(s5));
    assert(!isUnique3(s6));

    cout << "OK!" << endl;
    
    return 0;
}