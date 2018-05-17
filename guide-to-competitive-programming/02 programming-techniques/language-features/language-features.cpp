#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

//g++ -std=c++11 -O2 -Wall a.cpp -o executableName

void introduction(){
    // Input and output is sometimes a bottleneck in the program. The following lines
    // at the beginning of the code make input and output more efficient:
    ios::sync_with_stdio(0);
    cin.tie(0);

    //if the amount of data is unknown, we can do, for example:
    string xs[100001];
    int i = 0;
    string x;
    while(cin >> x){
        xs[i++] = x;
    }

    for(int j = 0; j < i; j++)
        cout << xs[j] << endl;
}

void inputAndOutput(){
    // cin
    // int a, b;
    // string x;
    // cin >> a >> b >> x;

    //cout
    int a = 123, b = 456;
    string x = "monkey";
    cout << a << " " << b << " " << x << "\n";

    // Input and output is sometimes a bottleneck in the program. The following lines
    // at the beginning of the code make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    // The C functions scanf and printf are an alternative to the C++ standard
    // streams. They are usually slightly faster, but also more difficult to use. The following
    // code reads two integers from the input:
    // int c, d;
    // scanf("%d %d", &c, &d);

    int e = 123, f = 456;
    printf("%d %d\n", e, f);

    // Sometimes the program should read a whole input line, possibly containing spaces.
    // This can be accomplished by using the getline function
    string s;
    getline(cin, s);

    cout << s << endl;

    // If the amount of data is unknown, the following loop is useful:
    // while (cin >> x) {
    // // code
    // }

    // In some contest systems, files are used for input and output. An easy solution for
    // this is to write the code as usual using standard streams, but add the following lines
    // to the beginning of the code
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // string line;
    // while(getline(cin, line)){
    //     cout << line << endl;
    // }
    // After this, the program reads the input from the file “input.txt” and writes the
    // output to the file “output.txt”
}

void freopenFunction(){
    // #include <stdio.h> contains freopen
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }
}


void workingWithNumbers(){

    double x = 0.1234567890123456789;
    cout << "By default C++ prints 6 decimals" << endl;
    cn(x)
    cout << "If we want more we can do: (for example for 9 decimals)" << endl;
    cout << "printf(" << "%.9f" << ", x);" << endl;
    printf("%.9f\n\n", x); //prints the value of x with 9 decimal places

    int a = 123456789;
    long long b = a*a;
    cout << "int a = 123456789;" << endl;
    cout << "long long b = a*a;" << endl;
    cout << "Error: ";
    cout << b << "\n\n"; // -1757895751
    
    cout << "b = (long long)a*a;" << endl;
    b = (long long)a*a;
    cout << "OK: ";
    cout << b << "\n\n"; // OK
    
    long long aOK = 123456789;
    cout << "long long aOK = 123456789;" << endl;
    b = aOK*aOK;
    cout << "b = aOK*aOK;" << endl;
    cout << "OK: ";
    cout << b << "\n"; // OK

    //prueba
    //__int128_t superNumber = 12345678901234567890123456789012345678;
    // cout << superNumber << "\n";
}

void floatingPointNumber(){

    double x = 0.3*3+0.1;
    printf("%.20f\n", x); // 0.99999999999999988898

    double y = 0.3*3;
    cn(y)//0.9
    printf("%.20f\n", y);// 0.89999999999999991118
    y += 0.1;
    printf("%.20f\n", y);// 0.99999999999999988898
    y *= 5; y /= 7; y /=5; y *= 7; 
    printf("%.20f\n", y);// 1.00000000000000000000

    //x = 0.99999999999999988898 and y = 1.00000000000000000000
    cout << (x == y) << endl;// false => too risky compare two floating point with ==
    //A better way
    cout << (abs(x-y) < 1e-9) << endl;// true 

    //Example
    if (abs(x-y) < 1e-9) {
    // a and b are equal
    }
}


void shorteningCode(){
    typedef long long ll;
    ll a = 123456789;
    ll b = 987654321;
    cout << a*b << "\n";

    typedef vector<int> vi;
    typedef pair<int,int> pi;

    #define F first
    #define S second
    #define PB push_back
    #define MP make_pair
    vector<pi> v;
    int i = 0, x1 = 1, x2 = 2, y1 = 3, y2 = 4;
    // v.push_back(make_pair(y1,x1));
    v.PB(MP(y1,x1));
    // v.push_back(make_pair(y2,x2));
    v.PB(MP(y2,x2));
    // int d = v[i].first+v[i].second;
    int d = v[i].F+v[i].S;
    cout << d << endl;
    #define REP(i,a,b) for (int i = a; i <= b; i++)
    int n = 100;
    REP(i,1,n) {
        //search(i);
    }
    vi w;
    w.PB(i);
}


int main(){
    // introduction();
    // inputAndOutput();
    // freopenFunction();
    // workingWithNumbers();
    // floatingPointNumber();
    // shorteningCode();
}