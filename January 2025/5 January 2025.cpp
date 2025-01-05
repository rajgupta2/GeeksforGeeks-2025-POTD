/*
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.
*/
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int res=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]<target) res++;
                else break;
            }
        }
        return res;
    }
};