class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for(char c : s) {
            if(c == '(') {
                balance++;
            }
            else if(c == ')') {
                balance--;

                if(balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string curr = q.front();
                q.pop();

                // First valid level = minimum removals
                if(isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate next level after finding valid strings
                if(found)
                    continue;

                for(int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses
                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if(found)
                break;
        }

        return ans;
    }
};