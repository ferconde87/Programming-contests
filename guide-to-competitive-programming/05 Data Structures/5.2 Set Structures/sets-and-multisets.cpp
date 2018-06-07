#include <bits/stdc++.h>

using namespace std;

// Multiset
multiset<int> ms;

void insert_in_multiset(){
    multiset<int> s;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    cout << ms.count(5) << "\n"; // 3
}

void erase_multiset(){
    ms.erase(5);
    cout << ms.count(5) << "\n"; // 0
}

void erase_only_one_copy(){
    insert_in_multiset();
    ms.erase(ms.find(5));//le pasamos el iterador
    cout << ms.count(5) << endl; // 2
}


//Set
set<int> s;

void insert_some_elements(){
    s.insert(1);
    s.insert(6);
    s.insert(2);
    s.insert(4);
    s.insert(5);
}

void set_basics(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3)
    << "\n"; // 1
    cout << s.count(4)
    << "\n"; // 0
    s.erase(3);
    s.insert(4);
    cout << s.count(3)
    << "\n"; // 0
    cout << s.count(4)
    << "\n"; // 1
}

//An important property of sets is that all their elements are distinct
void only_unique_elements(){
    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(3);
    cout << s.count(3) << "\n"; // 1
}

void iterate_over_sets(){
    insert_some_elements();
    cout << "size of s: " << s.size() << "\n";
    cout << "elements of s: ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "\n";
}

void using_find(){
    //s = {1, 2, 4, 5, 6}
    int x = 7;
    auto it = s.find(x);
    if(it == s.end()){
        cout << "No, " << x << " isn't in the set" << endl;
    }

    x = 4;
    it = s.find(x);
    if(it != s.end()){
        cout << "Yes, " << x << " is in the set" << endl;
    }
}

void min_and_max_elements(){
    auto first = s.begin();
    auto last = s.end(); last--;
    cout << *first << " " << *last << "\n";
}

void lower_and_upper_bounds(){
    int x = 3;
    cout << *s.lower_bound(x) << "\n";//4 => smallest but at least 3
    cout << *s.upper_bound(x) << "\n";//4 => larger than 3
    x = 4;
    cout << *s.lower_bound(x) << "\n";//4 => smallest but at least 3
    cout << *s.upper_bound(x) << "\n";//5 => larger than 4
}

int main(){
    
    //Sets
    cout << "Set\n";
    set_basics();
    only_unique_elements();
    iterate_over_sets();
    using_find();
    min_and_max_elements();
    lower_and_upper_bounds();

    //MultiSet
    cout << "\nMultiset\n";
    insert_in_multiset();
    erase_multiset();
    erase_only_one_copy();

    return 0;
}