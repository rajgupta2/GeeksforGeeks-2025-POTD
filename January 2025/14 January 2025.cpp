/*
Equilibrium Point
Given an array of integers arr[], the task is to find the first equilibrium point in the array.
The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists.
*/
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        int newSum=0;
        for(int i=0;i<n;i++){
            int rem=sum-newSum-arr[i];
            if(newSum==rem) return i;
            newSum+=arr[i];
        }
        return -1;
    }
};