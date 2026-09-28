class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')') st.pop();
            if(s[i]=='('){
                st.push(s[i]);
                count = max(count,(int)st.size());
            }
        }

        return count;
    }
};