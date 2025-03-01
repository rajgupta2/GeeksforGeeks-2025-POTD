/*
Decode the string
Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets.
Note: The test cases are generated so that the length of the output string will never exceed 10^5.
*/
class Solution
{
public:
    string decodedString(string &s)
    {
        stack<char> st;

        // Traverse the input string
        for (int i = 0; i < s.length(); i++)
        {
            // Push characters into the stack until ']' is encountered
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            // Decode when ']' is found
            else
            {
                string temp;

                // Pop characters until '[' is found
                while (!st.empty() && st.top() != '[')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end()); // Reverse extracted string
                // Remove '[' from the stack
                st.pop();

                string num;
                // Extract the number (repetition count) from the stack
                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }

                // Convert extracted number to integer
                int number = stoi(num);
                string repeat;

                // Repeat the extracted string 'number' times
                for (int j = 0; j < number; j++)
                    repeat.append(temp);

                // Push the expanded string back onto the stack
                for (char c : repeat)
                    st.push(c);
            }
        }

        string res;
        // Pop all characters from stack to form the final result
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        // Reverse to get the correct order
        reverse(res.begin(), res.end());
        return res;
    }
};