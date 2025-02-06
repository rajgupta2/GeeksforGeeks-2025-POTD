/*
Construct Tree from Inorder & Preorder
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

Note: The output is written in postorder traversal.
*/
Node *buildTreeRecur(unordered_map<int,int> &mp, vector<int> &preorder,
                         int &preIndex, int left, int right) {

    // For empty inorder array, return null
    if (left > right)
        return nullptr;

    int rootVal = preorder[preIndex];
    preIndex++;

    // create the root Node
    Node *root = new Node(rootVal);

    // find the index of Root element in the in-order array.
    int index = mp[rootVal];

    // Recursively create the left and right subtree.
    root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);

    return root;
}