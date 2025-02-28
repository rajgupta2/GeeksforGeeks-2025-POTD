/*
Evaluation of Postfix Expression
You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.
Key Details:
The valid operators are '+', '-', '*', and '/'.
Each operand is guaranteed to be a valid integer or another expression.
The division operation between two integers always rounds the result towards zero, discarding any fractional part.
No division by zero will occur in the input.
The input is a valid arithmetic expression in Reverse Polish Notation.
The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
*/
class Solution {
    public:
      int evaluate(vector<string>& arr) {
          // code here
          stack<int> st;

      // Loop through each element in the vector
      for (string token : arr) {

          // If it's an operand (number), push it onto
          // the stack
          if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
              st.push(stoi(token));
          }

          // Otherwise, it must be an operator
          else {
              int val1 = st.top();
              st.pop();
              int val2 = st.top();
              st.pop();

              if (token == "+") {
                  st.push(val2 + val1);
              } else if (token == "-") {
                  st.push(val2 - val1);
              } else if (token == "*") {
                  st.push(val2 * val1);
              } else if (token == "/") {
                  st.push(val2 / val1);
              }
          }
      }
      return st.top();
      }
  };