#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Approach with two iterators

ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode * node = A;
    int counter = 0;
    while(node != NULL && counter < B){
        counter++;
        node = node->next;
    }
    if(node == NULL || counter < B) return A->next;
    
    ListNode * prev = A;
    while(node->next != NULL){
        node = node->next;
        prev = prev->next;
    }
    prev->next = prev->next->next;
    
    return A;
}

int main(){

    return 0;
}