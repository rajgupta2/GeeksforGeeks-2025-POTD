/*
K Sum Paths
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).
*/
class Solution {
    public:
      int sumK(Node *root, int k) {
         unordered_map<int, int> prefSums;
         return countPathsUtil(root, k, 0, prefSums);
      }
      int countPathsUtil(Node* node, int k, int currSum, unordered_map<int, int>& prefSums) {
          if (node == nullptr)
              return 0;

          int pathCount = 0;
          currSum += node->data;
          if (currSum == k)
              pathCount++;
          pathCount += prefSums[currSum - k];
          prefSums[currSum]++;

          pathCount += countPathsUtil(node->left, k, currSum, prefSums);
          pathCount += countPathsUtil(node->right, k, currSum, prefSums);

          prefSums[currSum]--;

          return pathCount;
      }


  };