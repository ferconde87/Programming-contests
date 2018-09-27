#include <bits/stdc++.h>

using namespace std;

//Time complexity : O(mn)O(mn)
//Space complexity : O(1)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    
    ListNode * nodeA = headA;
    while(nodeA != NULL){
        ListNode * nodeB = headB;
        while(nodeB != NULL){
            if(nodeA == nodeB) return nodeB;
            nodeB = nodeB->next;
        }
        nodeA = nodeA->next;
    }

    return NULL;
}

int main(){
    ListNode * a1 = new ListNode(1);
    ListNode * a2 = new ListNode(2);
    ListNode * a3 = new ListNode(3);
    ListNode * c1 = new ListNode(4);
    ListNode * c2 = new ListNode(5);
    ListNode * b1 = new ListNode(6);
    ListNode * b2 = new ListNode(7);
    ListNode * b3 = new ListNode(8);
    a1->next = a2;
    a2->next = a3;
    a3->next = c1;
    c1->next = c2;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    c1->next = c2;

    ListNode * intersection = getIntersectionNode(a1,b1);
    if(intersection == NULL) cout << "NULL\n";
    else cout << intersection->val << endl;
    

    return 0;

}