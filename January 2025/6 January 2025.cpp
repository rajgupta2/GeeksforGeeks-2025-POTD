/*
Sum Pair closest to target
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.
*/
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int> res;
        int minDiff=INT_MAX;
        sort(arr.begin(),arr.end());
        int left=0;
        int right=arr.size()-1;
        while(left<right){

            int sum=arr[left]+arr[right];
            if (abs(target - sum) < minDiff) {
               minDiff = abs(target - sum);
               res = {arr[left], arr[right]};
            }

            if(sum>target) right--;
            else if(sum<target) left++;
            else return res;
        }
        return res;
    }
};
