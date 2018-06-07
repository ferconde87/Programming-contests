#include <bits/stdc++.h>

using namespace std;

//Map
void maps(){
    cout << "Maps\n";
    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; // 3

    // If the value of a key is requested but the map does not contain it, the key is
    // automatically added to the map with a default value
    cout << m["aybabtu"] << "\n"; // 0
    //The function count checks if a key exists in a map:
    if (m.count("aybabtu")) {
        // key exists
        cout << "Now aybabtu exists for the m[aybabtu] operation\n" << endl;
    }
}

//Priority Queue
void max_heap(){
    cout << "Max-Heap\n";
    //default max-heap
    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n"; // 7
    q.pop();
    cout << q.top() << "\n"; // 5
    q.pop();
    q.push(6);
    cout << q.top() << "\n\n"; // 6
    q.pop();
}

// If we want to create a priority queue that supports finding and removing the
// smallest element, we can do it as follows:
void min_heap(){
    cout << "Min-Heap\n";
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n"; // 2
    q.pop();
    cout << q.top() << "\n"; // 3
    q.pop();
    q.push(6);
    cout << q.top() << "\n"; // 5
    q.pop();
}

void priority_queues(){
    max_heap();
    min_heap();
}

int main(){

    maps();

    priority_queues();

    return 0;
}

