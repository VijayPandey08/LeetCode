/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans, int depth) {
        if (root == NULL) {
            return;
        }

        if (depth == ans.size()) {
            ans.push_back(root->val);
        }

        if (root->right)
            solve(root->right, ans, depth + 1);
        if (root->left)
            solve(root->left, ans, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        // int left = 0;
        // int right = 0;
        int depth = 0;
        vector<int> ans;
        solve(root, ans, depth);
        return ans;
    }
};