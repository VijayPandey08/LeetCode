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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int left_h = height(root->left);
        int right_h = height(root->right);

        bool b1 = (abs(right_h - left_h) <= 1) ? true : false;

        bool b2 = isBalanced(root->left);
        bool b3 = isBalanced(root->right);


        return (b1 && b2 && b3);
    }
};