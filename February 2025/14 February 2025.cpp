/*
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).
*/
class Solution
{
public:
    void correctBSTUtil(Node *root, Node *&first, Node *&middle,
                        Node *&last, Node *&prev)
    {
        if (root == nullptr)
            return;

        // Recur for the left subtree
        correctBSTUtil(root->left, first, middle, last, prev);

        // If this node is smaller than the previous node,
        // it's violating the BST rule.
        if (prev && root->data < prev->data)
        {

            // If this is the first violation, mark these
            // two nodes as 'first' and 'middle'
            if (!first)
            {
                first = prev;
                middle = root;
            }

            // If this is the second violation,
            // mark this node as last
            else
                last = root;
        }

        // Mark this node as previous
        prev = root;

        // Recur for the right subtree
        correctBSTUtil(root->right, first, middle, last, prev);
    }

    void correctBST(Node *root)
    {
        // add code here.
        Node *first = nullptr, *middle = nullptr,
             *last = nullptr, *prev = nullptr;

        // Set the pointers to find out two nodes
        correctBSTUtil(root, first, middle, last, prev);

        // Fix (or correct) the tree
        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
};