/*
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1==nullptr) return head2;
        if(head2==nullptr) return head1;

        Node* curr1=head1,*curr2=head2;
        Node* dummy=new Node(-1);
        Node *curr=dummy;
        while(curr1!=nullptr && curr2!=nullptr){
            if(curr1->data<curr2->data)
            {
                curr->next=curr1;
                curr=curr->next;
                curr1=curr1->next;
            }else{
                curr->next=curr2;
                curr=curr->next;
                curr2=curr2->next;
            }
        }
        if(curr1==nullptr){
            curr->next=curr2;
        }else{
            curr->next=curr1;
        }
        return dummy->next;

    }
};