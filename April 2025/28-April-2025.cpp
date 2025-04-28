//Maximum sum of Non-adjacent nodes
class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
int getMaxSumUtil(Node* node, unordered_map<Node*, int>& memo) {
    if (node == nullptr) {
      
        // If the node is null, the sum is 0
        return 0;
    }
    
    // If the result is already computed, return it from memo
    if (memo.find(node) != memo.end()) {
        return memo[node];
    }

    // Calculate the maximum sum including the current node
    int incl = node->data;
    
    // If the left child exists, include its grandchildren
    if (node->left) {
        incl += getMaxSumUtil(node->left->left, memo) + 
                getMaxSumUtil(node->left->right, memo);
    }

    // If the right child exists, include its grandchildren
    if (node->right) {
        incl += getMaxSumUtil(node->right->left, memo) + 
                getMaxSumUtil(node->right->right, memo);
    }

    // Calculate the maximum sum excluding the current node
    int excl = getMaxSumUtil(node->left, memo) + 
               getMaxSumUtil(node->right, memo);

    // Store the result in memo and return 
  	// the maximum of incl and excl
    memo[node] = max(incl, excl);
    return memo[node];
}

// Function to compute the maximum
// sum of non-adjacent nodes
int getMaxSum(Node* root) {
    unordered_map<Node*, int> memo;
    return getMaxSumUtil(root, memo);
}
};
