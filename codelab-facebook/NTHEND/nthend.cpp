#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(N)
//Space Complexity O(1)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Approach knowing the length 

ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode * node = A;
    int counter = 0;
    while(node != NULL){
        counter++;
        node = node->next;
    }
    int target = counter - B;
    if(target <= 0) return A->next;
    counter = 0;
    node = A;
    while(counter < target - 1){
        node = node->next;
        counter++;
    }
    node->next = node->next->next;
    return A;
}

int main(){

    return 0;
}