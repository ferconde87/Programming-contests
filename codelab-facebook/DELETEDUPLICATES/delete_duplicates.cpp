#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* delete_duplicates(ListNode* A){
    ListNode* node = A;
    ListNode* next;
    while(node != NULL){
        next = node->next;
        while(next != NULL && next->val == node->val){
            next = next->next;
        }
        node->next = next;
        node = next;
    }
    return A;
}

void print(ListNode* A){
    ListNode* node = A;
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
}

int main(){

    ListNode * a1 = new ListNode(1);
    ListNode * a2 = new ListNode(2);
    ListNode * a3 = new ListNode(2);
    ListNode * a4 = new ListNode(3);
    ListNode * a5 = new ListNode(4);
    ListNode * a6 = new ListNode(4);
    ListNode * a7 = new ListNode(4);
    ListNode * a8 = new ListNode(5);
    ListNode * a9 = new ListNode(5);
    ListNode * a10 = new ListNode(6);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    a6->next = a7;
    a7->next = a8;
    a8->next = a9;
    a9->next = a10;

    ListNode* a_without_duplicates = delete_duplicates(a1);
    print(a_without_duplicates);

    return 0;
}