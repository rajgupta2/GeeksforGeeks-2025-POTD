class Solution {
    public:
      int getSingle(vector<int> &arr) {
          // code here
              unordered_map<int, int> freq;

      // Count the frequency of each number in the array
      for (int num : arr) {
          freq[num]++;
      }

      // Find the number that occurs only once
      for (auto it : freq) {
          if (it.second == 1)
              return it.first;
      }

      // Return 0 if no unique element is found
      return 0;

      }
  };