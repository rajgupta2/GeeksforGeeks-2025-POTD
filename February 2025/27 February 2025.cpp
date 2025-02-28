/*
Get Min from Stack
Given q queries, You task is to implement the following four functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the minimum element from the stack.
*/
class Solution {
    private:
      stack<pair<int, int> > s;
    public:
      Solution() {
          // code here
      }

      void push(int x) {
          int newMin = s.empty() ? x : min(x, s.top().second);

          // we push the pair of given element and newMin into stack
          s.push({ x, newMin });
      }

      // Remove the top element from the Stack
      void pop() {
          if (!s.empty()) {
              s.pop();
          }
      }

      // Returns top element of the Stack
      int peek() {
          if (s.empty()) {
              return -1;
          }

          int top = s.top().first;
          return top;
      }

      // Finds minimum element of Stack
      int getMin() {
          if (s.empty()) {
              return -1;
          }

          int mn = s.top().second;
          return mn;
      }
  };