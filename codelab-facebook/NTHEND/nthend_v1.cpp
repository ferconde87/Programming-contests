#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode* node = A;
    int n = 0;
    //Calculate size of the ListNode
    while(node != NULL){
        n++;
        node = node->next;
    }
    int indexToDelete = n - B;
    if(B > n || n == 1 || !indexToDelete) return A->next;
    n = 1;
    node = A;
    ListNode* next = node->next;
    while(next != NULL){
        if(indexToDelete == n){
            node->next = next->next;
            break;
        }
        n++;
        node = next;
        next = next->next;
    }
    return A;
}

int main(){


    return 0;
}