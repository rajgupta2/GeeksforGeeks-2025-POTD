/*
Count all triplets with given sum in sorted array
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.
TC=O(Nsquare) SC=O(1)
*/
int countTriplets(vector<int> &arr, int target) {
        // Code Here

        int n=arr.size();
        int res=0;

        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<k) j++;
                else if(sum>k) k--;
                else{
                    //count number of frequency with same element
                    int el1=arr[j],el2=arr[k];
                    int cnt1=0,cnt2=0;
                    while(j<=k && el1==arr[j])
                    {
                        j++;
                        cnt1++;
                    }
                    while(j<=k && el2==arr[k])
                    {
                        k--;
                        cnt2++;
                    }
                    if(el1==el2)
                     res+=(cnt1 * (cnt1 - 1)) / 2;
                    else
                    res+=cnt1*cnt2;
                }
            }
        }
        return res;
    }