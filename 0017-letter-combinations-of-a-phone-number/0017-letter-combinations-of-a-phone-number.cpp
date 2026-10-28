
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> letters = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            string choices = letters[digits[index] - '0'];

            for (char ch : choices) {
                current.push_back(ch);

                backtrack(index + 1);

                current.pop_back(); // Backtrack
            }
        };

        backtrack(0);
        return ans;
    }
};
