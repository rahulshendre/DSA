class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
