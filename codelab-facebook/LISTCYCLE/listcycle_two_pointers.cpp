#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode* firstp = head;
    ListNode* secondp = head;
    bool isCycle = false;

    while(firstp != NULL && secondp != NULL) {
        firstp = firstp->next;
        if (secondp->next == NULL) return NULL;
        secondp = secondp->next->next;
        if (firstp == secondp) { isCycle = true; break; }
    }

    if(!isCycle) return NULL;
    firstp = head;
    while( firstp != secondp) {
        firstp = firstp->next;
        secondp = secondp->next;
    }

    return firstp;

    
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
    assert(result==c);

    ListNode * a1 = new ListNode(1);
    ListNode * a2 = new ListNode(2);
    ListNode * a3 = new ListNode(3);
    ListNode * a4 = new ListNode(4);
    ListNode * a5 = new ListNode(5);
    ListNode * a6 = new ListNode(6);
    ListNode * a7 = new ListNode(7);
    ListNode * a8 = new ListNode(8);
    ListNode * a9 = new ListNode(9);
    ListNode * a10 = new ListNode(10);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    a6->next = a7;
    a7->next = a8;
    a8->next = a9;
    a9->next = a10;
    a10->next = a7;


    result = detectCycle(a1);
    cout << result->val << endl;
    assert(result==a7);




    return 0;
}