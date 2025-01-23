/*
Clone List with Next and Random
You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.
Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.
Return the head of the copied linked list.
NOTE : Original linked list should remain unchanged.
*/
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        unordered_map<Node*,Node*> mp;
        Node* temp=head;
        while(temp!=nullptr){
            mp[temp]=new Node(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr)
            mp[temp]->next=mp[temp->next];
            if(temp->random!=nullptr)
            mp[temp]->random=mp[temp->random];
            temp=temp->next;

        }
        return mp[head];
    }
};