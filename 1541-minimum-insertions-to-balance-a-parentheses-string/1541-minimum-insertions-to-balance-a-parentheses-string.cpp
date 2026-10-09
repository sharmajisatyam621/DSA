class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // If there is another ')' next, consume it as a pair.
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert a ')' to complete the pair.
                    ans++;
                }

                // This closing pair must match an opening '('.
                if (open > 0) {
                    open--;
                }
                else {
                    // Insert a missing '('.
                    ans++;
                }
            }
        }

        // Each unmatched '(' needs two closing parentheses.
        ans += open * 2;

        return ans;
    }
};