/*
Detect Loop in linked list
*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        unordered_set<Node*> st;
        Node* curr=head;
        while(curr!=nullptr){
            if(st.find(curr)!=st.end()) return true;
            st.insert(curr);
            curr=curr->next;
        }
        return false;
    }
};