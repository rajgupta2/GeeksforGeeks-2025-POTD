/*
Longest substring with distinct characters
Difficulty: EasyAccuracy: 31.32%Submissions: 148K+Points: 2
Given a string s, find the length of the longest substring with all distinct characters.
*/
class Solution{
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int res=0;
        vector<bool>vis(26, false);
        int left=0,right=0;
        while(right<s.size()){

           while (vis[s[right] - 'a'] == true) {
                vis[s[left] - 'a'] = false;
                left++;
           }

           vis[s[right] - 'a'] = true;
           res = max(res, (right - left + 1));
           right++;
        }
        return res;
    }
};