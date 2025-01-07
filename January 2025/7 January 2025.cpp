/*
Pair with given sum in a sorted array
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes.
*/
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int res=0;
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum>target) right--;
            else if(sum<target) left++;
            else{
                int el1=arr[left];
                int el2=arr[right];
                int cnt1=0,cnt2=0;
                //left & right are equal so cnt here only and break
                if(el1==el2)
                {
                    cnt1=right-left+1;
                    res+=cnt1*(cnt1-1)/2;
                    break;
                }

                if(arr[left]==arr[left+1] && arr[right]==arr[right-1]){
                    for(int i=left;i<=right;i++){
                        if(arr[left]==arr[i]){
                            cnt1++;
                        }
                        if(arr[right]==arr[i]){
                            cnt2++;
                        }

                    }
                    res+=cnt1*cnt2;
                        left+=cnt1;
                        right-=cnt2;
                    continue;
                }
                else if(arr[left]==arr[left+1]) left++;
                else if(arr[right]==arr[right-1]) right--;
                else{
                  left++; right--;
                }
                res++;
            }
        }
        return res;
    }
};