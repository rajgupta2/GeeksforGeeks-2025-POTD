#include<bits/stdc++.h>
using namespace std;

//count number of subarray with sum equal to k
//TC=O(n)  & SC=O(n) i.e auxiliary space for unordered map.

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {

        int n=arr.size();
        unordered_map<int,int> mp;
        int sum=0,res=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) res++;

            if(mp.find(sum-k)!= mp.end())
             res+=mp[sum-k];

            mp[sum]++;
        }
        return res;
    }
};
