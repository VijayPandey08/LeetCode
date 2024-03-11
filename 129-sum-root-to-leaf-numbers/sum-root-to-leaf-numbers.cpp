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
int ans;
int val;
    void solve(TreeNode* root){
        if(root==NULL) return;
        val = val*10 + root->val;
        solve(root->left);
        solve(root->right);
        if(root->left == NULL && root->right==NULL){
            ans+=val;
        }
        val = val/10;
    }


    int sumNumbers(TreeNode* root) {
        ans = 0;
        val = 0;
        solve(root); 
        return ans;
    }
};