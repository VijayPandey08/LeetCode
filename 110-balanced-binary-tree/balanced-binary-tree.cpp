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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return max(leftheight,rightheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int left=height(root->left);
        int right=height(root->right);
        bool diff = (abs(left-right)<=1);
        
        bool left_side=isBalanced(root->left);
        bool right_side=isBalanced(root->right);

        if(diff && left_side && right_side){
            return true;
        }
        else{
            return false;
        }

    }
};