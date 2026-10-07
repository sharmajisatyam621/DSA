/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    long long target;

    void dfs(TreeNode* root, long long currentSum,
             unordered_map<long long, int>& prefix) {

        if(root == nullptr)
            return;

        currentSum += root->val;

        // Check if a path with targetSum exists
        if(prefix.count(currentSum - target)) {
            ans += prefix[currentSum - target];
        }

        // Add current prefix sum
        prefix[currentSum]++;

        dfs(root->left, currentSum, prefix);
        dfs(root->right, currentSum, prefix);

        // Backtrack
        prefix[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;

        unordered_map<long long, int> prefix;

        // Empty prefix
        prefix[0] = 1;

        dfs(root, 0, prefix);

        return ans;
    }
};