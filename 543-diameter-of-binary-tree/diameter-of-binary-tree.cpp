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

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL)
            return ans;

        int left_h = height(root->left);
        int right_h = height(root->right);
        int d1 = left_h + right_h ;

        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);


        return max({d1,d2,d3});
    }
};