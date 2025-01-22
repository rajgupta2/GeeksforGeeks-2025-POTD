/*
Add Number Linked Lists
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.
For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.
Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
*/
class Solution {
  public:
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* prev=nullptr,*curr=head;
        while(curr!=nullptr){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node* curr1=reverse(num1);
        Node* curr2=reverse(num2);

        int carry=0;
        Node *dummy=new Node(-1);
        Node* curr=dummy;
        while(curr1!=nullptr || curr2!=nullptr){
            int sum=0;
            if(curr1!=nullptr)
            {
                sum+=curr1->data;
                curr1=curr1->next;
            }
            if(curr2!=nullptr)
            {
                sum+=curr2->data;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum%=10;
            curr->next=new Node(sum);
            curr=curr->next;
        }
        if(carry){
            curr->next=new Node(1);
        }
        Node* res= reverse(dummy->next);
        while(res->data==0){
            res=res->next;
        }
        return res;
    }
};