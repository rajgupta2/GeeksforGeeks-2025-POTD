/*
Reverse a linked list
Given the head of a linked list, the task is to reverse this list and return the reversed head.
*/
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(head==nullptr) return head;
        struct Node* curr=head;
        struct Node* prev=nullptr;
        while(curr!=nullptr){
            struct Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
};