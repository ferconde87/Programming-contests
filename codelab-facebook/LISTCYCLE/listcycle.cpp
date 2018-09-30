#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* A) {
    unordered_set<int> hashSet;
    ListNode* node = A;
    while(node != NULL){
        int val = node->val;
        auto it = hashSet.find(val);
        if(it != hashSet.end()) return node;
        hashSet.insert(val);
        node = node->next;
    }
    return NULL;
}

int main(){

    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = c;

    ListNode* result = detectCycle(a);
    cout << result->val << endl;
    // assert(detectCycle(a)==c);

    return 0;
}