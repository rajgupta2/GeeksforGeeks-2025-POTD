/*
Product array puzzle
Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.
*/
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,1);
        int startMul=1;
        int lastMul=1;
        for(int i=0;i<n;i++){
            res[i]*=startMul;
            startMul*=arr[i];

            res[n-1-i]*=lastMul;
            lastMul*=arr[n-1-i];
        }
        return res;

    }
};