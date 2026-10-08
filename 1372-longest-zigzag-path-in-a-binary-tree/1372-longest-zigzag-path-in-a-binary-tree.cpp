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

    // returns {left ZigZag length, right ZigZag length}
    pair<int,int> dfs(TreeNode* root) {
        if(root == nullptr)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftPath = 0;
        int rightPath = 0;

        if(root->left)
            leftPath = 1 + left.second;

        if(root->right)
            rightPath = 1 + right.first;

        ans = max(ans, max(leftPath, rightPath));

        return {leftPath, rightPath};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};