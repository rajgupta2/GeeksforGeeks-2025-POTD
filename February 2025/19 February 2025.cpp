/*
Merge K sorted linked lists
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.
*/
class Solution {
    public:
      Node* mergeTwo(Node* head1, Node* head2) {

      Node* dummy = new Node(-1);
      Node* curr = dummy;

      while (head1 != nullptr && head2 != nullptr) {

          if (head1->data <= head2->data) {
              curr->next = head1;
              head1 = head1->next;
          } else {
              curr->next = head2;
              head2 = head2->next;
          }
          curr = curr->next;
      }

      if (head1 != nullptr) {
          curr->next = head1;
      } else {
          curr->next = head2;
      }
      return dummy->next;
      }

      Node* mergeKLists(vector<Node*>& arr) {

      // Base case for 0 lists
      if (arr.size()==0) return nullptr;
      Node* head=arr[0];
      for(int i=1;i<arr.size();i++){
          head=mergeTwo(head, arr[i]);
      }
      return head;
      }
  };