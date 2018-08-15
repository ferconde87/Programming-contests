#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

bool is_ipv4(string input){
    size_t from = 0;
    for(int k = 0; k < 4; k++){//look for each ipv4 format point 
        size_t to = input.find_first_of('.', from);
        if(to == string::npos && k < 3) return false;
        string chunk = input.substr(from, to); 
        try {
            int number = stoi(chunk);
            if(number < 0 || number > 255) return false;
        }
        catch(invalid_argument& e){
            // cn(chunk)
            return false;
        }
        catch(out_of_range& e){
            // cn(chunk)
            return false;
        }
        from = to+1;
    }
    return true;
}

bool is_ipv6(string input){
    size_t from = 0;
    for(int k = 0; k < 8; k++){//look for each ipv4 format point 
        size_t to = input.find_first_of(':', from);
        if(to == string::npos && k < 7) return false;
        string chunk = input.substr(from, to); 
        try {
            int number = stoi(chunk, nullptr, 16);
            if(number < 0 || number > 65535) return false;
        }
        catch(invalid_argument& e){
            // cn(chunk)
            return false;
        }
        catch(out_of_range& e){
            // cn(chunk)
            return false;
        }
        from = to+1;
    }
    return true;   
}
void checkIPs(string *input, int size){
    for(int i = 0; i < size; i++){
        if(is_ipv4(input[i])){
            cout << "IPv4\n";
        }else if(is_ipv6(input[i])){
            cout << "IPV6\n";
        }else{
            cout << "Neither\n";
        }
    }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    string input[n];
    for(int i = 0; i < n; i++) getline(cin, input[i]);
    checkIPs(input, n);
    return 0;
}