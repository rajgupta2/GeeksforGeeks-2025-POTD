/*
Serialize and deserialize a binary tree
Difficulty: MediumAccuracy: 51.67%Submissions: 92K+Points: 4Average Time: 45m
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions
serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).
*/
class Solution {
    public:
      // Function to serialize a tree and return a list containing nodes of tree.
      void serializePreOrder(Node* root, vector<int> &arr) {

      // Push -1 if root is null.
      if (root == nullptr) {
          arr.push_back(-1);
          return;
      }

      // Push the root into result.
      arr.push_back(root->data);

      // Recursively traverse the
      // left and right subtree.
      serializePreOrder(root->left, arr);
      serializePreOrder(root->right, arr);
      }
      vector<int> serialize(Node *root) {
          vector<int> arr;
          serializePreOrder(root, arr);
          return arr;
      }

      Node* deserializePreOrder(int &i, vector<int> &arr) {

          // -1 meres null.
          if (arr[i] == -1){
              i++;
              return nullptr;
          }

          // Create the root node.
          Node* root = new Node(arr[i]);
          i++;

          // Create the left and right subtree.
          root->left = deserializePreOrder(i, arr);
          root->right = deserializePreOrder(i, arr);

          return root;
      }

      // Function to deserialize a list and construct the tree.
      Node *deSerialize(vector<int> &arr) {
          // Your code here
          int i = 0;
          return deserializePreOrder(i, arr);
      }
  };