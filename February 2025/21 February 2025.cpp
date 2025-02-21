/*
Parenthesis Checker
*/
class Solution {
    public:
      bool isBalanced(string& s) {
          // code here
          stack<char> st;
          for(int i=0;i<s.size();i++){
              if(s[i]=='(' || s[i]=='[' || s[i]=='{')
               st.push(s[i]);
              else{
                  if(st.size()==0) return false;
                  if(st.top()=='(' && s[i]!=')') return false;
                  else if(st.top()=='{' && s[i]!='}') return false;
                  else if(st.top()=='[' && s[i]!=']') return false;
                  st.pop();
              }
          }
          if(!st.empty()) return false;
          return true;
      }
  };