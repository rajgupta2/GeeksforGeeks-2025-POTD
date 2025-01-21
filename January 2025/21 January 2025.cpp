/*
Linked List Group Reverse
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // If newHead is null, set it to the
          // last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Connect the previous group to the
          // current reversed group
        if (tail != nullptr) {
            tail->next = prev;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
    }
};