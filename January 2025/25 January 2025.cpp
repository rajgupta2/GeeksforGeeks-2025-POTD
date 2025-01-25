/*
Find the first node of loop in linked list
Given a head of the singly linked list. If a loop is present in the list then return the first node of the loop else return NULL.
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.
*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        unordered_set<Node*>  st;
        Node* curr=head;
        while(curr!=nullptr){
            if(st.find(curr)!=st.end()) return curr;
            st.insert(curr);
            curr=curr->next;
        }
        return nullptr;
    }
};