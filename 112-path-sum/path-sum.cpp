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
    bool solve(TreeNode* root, int targetSum, int sum){
        //   base case
        if(root==NULL) return false;

        if(sum+root->val==targetSum && root->left==NULL && root->right==NULL){
            return true;
        }

        bool a = solve(root->left,targetSum,sum+root->val);
        bool b = solve(root->right,targetSum,sum+root->val);

        return a|b; 

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return solve(root,targetSum,0);
    }
};