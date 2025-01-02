#include<bits/stdc++.h>
using namespace std;

//Given an array of string. You have to return a groups of group of anagram.
//Anagrams are those string which contains the same characters with repositioned.
//TC= O(n(klogk + logn)) + O(n)
//SC= O(n*k) where k is the avg length of the strings.

class Solution{
 public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        int n = arr.size();
        map<string, vector<string>> mp;
        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            sort(s.begin(), s.end());
            mp[s].push_back(arr[i]);
        }
        vector<vector<string>> res;
        for (auto it : mp)
        {
            vector<string> curr_anagrams = it.second;
            res.push_back(curr_anagrams);
        }
        return res;
    }
};
