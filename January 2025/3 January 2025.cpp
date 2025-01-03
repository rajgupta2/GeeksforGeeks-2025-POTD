/*
Count Subarrays with given XOR
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size();
        int xr=0;
        long int res=0;
        for(int i=0;i<n;i++){
            xr^=arr[i];
            if(xr==k) res++;

            res+=(long int)mp[xr^k];

            mp[xr]++;
        }
        return res;
    }
};