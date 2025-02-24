/*
Next Greater Element
Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--)
        {

            // Pop elements from the stack that are less
            // than or equal to the current element
            while (!stk.empty() && stk.top() <= arr[i])
            {
                stk.pop();
            }

            // If the stack is not empty, the top element
            // is the next greater element
            if (!stk.empty())
            {
                res[i] = stk.top();
            }

            // Push the current element onto the stack
            stk.push(arr[i]);
        }

        return res;
    }
};