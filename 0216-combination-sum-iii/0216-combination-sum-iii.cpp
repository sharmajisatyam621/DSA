
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, int k, int target) {
        if (current.size() == k) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        if (target <= 0) return;

        for (int i = start; i <= 9; i++) {
            current.push_back(i);

            backtrack(i + 1, k, target - i);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        current.clear();

        backtrack(1, k, n);

        return ans;
    }
};

