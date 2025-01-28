/*
Permutations of a String
Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.
*/
class Solution {
  public:
    void findPermutation(int ind,int n,string newstr,string &s,unordered_set<string> &st) {
        if(ind==n){
            st.insert(newstr);
            return;
        }
        //choose
        findPermutation(ind+1,n,newstr+s[ind],s,st);
        //not-choose
        findPermutation(ind+1,n,newstr,s,st);

    }
    vector<string> findPermutation(string &s) {

        vector<string> ans;
        sort(s.begin(),s.end());
         do {
             ans.push_back(s);
        } while (next_permutation(s.begin(),s.end()));
        return ans;
    }
};