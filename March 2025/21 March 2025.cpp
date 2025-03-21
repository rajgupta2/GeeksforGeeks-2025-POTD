/*
Stickler Thief
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
Determine the maximum amount he can loot.
*/
class Solution {
    public:
      int maxLootRec(const vector<int>& hval, int n, vector<int>& memo) {

          if (n <= 0) return 0;
          if (n == 1) return hval[0];
          if (memo[n] != -1) return memo[n];

          int pick = hval[n - 1] + maxLootRec(hval, n - 2, memo);
          int notPick = maxLootRec(hval, n - 1, memo);

          memo[n] = max(pick, notPick);
          return memo[n];
      }

      int findMaxSum(vector<int>& arr) {
           int n = arr.size();
          vector<int> memo(n + 1, -1);
          return maxLootRec(arr, n, memo);

      }
  };