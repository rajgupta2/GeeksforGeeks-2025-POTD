/*
Given a string s of lowercase English alphabets, your task is to return the maximum number of substrings formed, after possible partitions (probably zero) of s such that no two substrings have a common character.
*/
class Solution {
  public:
    int maxPartitions(string &str) {
        // code here
        int i = 0, j = 0, k = 0;
    int c = 0, r = 0;

    unordered_map<char,int> m;


    for (i = str.length() - 1;
        i >= 0;
        i--) {

        if (m[str[i]] == 0) {
            m[str[i]] = i;
        }
    }

    i = 0;
    k = m[str[i]];

    for (i = 0; i < str.length(); i++) {

        if (i <= k) {
            c = c + 1;
            k = max(k, m[str[i]]);
        }
        else {

            r = r + 1;
            c = 1;

            // Update k for the
            // next partition
            k = max(k, m[str[i]]);
        }
    }

    // Add the last partition
    if (c != 0) {
        r = r + 1;
    }
    return r;
    }
};