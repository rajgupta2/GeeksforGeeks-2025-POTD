/*
Rotate a Linked List
Given the head of a singly linked list, your task is to left rotate the linked list k times.
*/
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        Node * curr=head;
        if(k==0 || head==nullptr) return head;
        int len=1;
        while(curr->next!=nullptr){
            curr=curr->next;
            len++;
        }
        Node *tail=curr;

        k=k%len;
        if(k<=0) return head;
        curr=head;
        for(int i=1;i<k;i++){
            curr=curr->next;
        }

        Node * newhead=curr->next;
        curr->next=nullptr;
        tail->next=head;
        return newhead;
    }
};