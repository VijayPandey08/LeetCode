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
        string ans = "";
    void solve(TreeNode* root, string curr) {
        if (root == NULL)
            return;
        curr = char('a' + root->val) + curr;
        if (root->left == NULL && root->right == NULL) {
            if (ans == "" || ans > curr) {
                ans = curr;
            }
            return;
        }
        solve(root->left, curr);
        solve(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        solve(root, curr);
        return ans;
    }
};