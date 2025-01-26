/*
Remove loop in Linked List
Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).
*/
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        unordered_set<Node*> st;
        Node* curr=head;
        while(curr!=nullptr){
            if(st.find(curr->next)!=st.end()){
              curr->next=nullptr;
            }
            st.insert(curr);
            curr=curr->next;
        }
    }
};