class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int partSize = part.size();

        // Traverse the input string
        for (char c : s) {
            st.push(c); // Push the current character to the stack

            // Check if the top of the stack matches `part`
            if (st.size() >= partSize) {
                string temp = "";
                for (int i = 0; i < partSize; i++) {
                    temp = st.top() + temp; // Build the potential match string
                    st.pop();
                }

                // If `part` doesn't match, push back the characters
                if (temp != part) {
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }
            }
        }

        // Build the final result string from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
