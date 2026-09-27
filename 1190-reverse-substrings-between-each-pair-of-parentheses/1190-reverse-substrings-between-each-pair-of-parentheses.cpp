class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;

        for (char c : s) {
            if (c == ')') {
                
                string temp;

                while (st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                // Remove '('
                st.pop_back();

                // Push reversed part back
                for (char x : temp) {
                    st.push_back(x);
                }
            }
            else {
                st.push_back(c);
            }
        }

        return string(st.begin(), st.end());
    }
};