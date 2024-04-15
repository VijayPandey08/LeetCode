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

    void solve(TreeNode* root, int val){
        if(root==NULL) return;
        val = val*10 + root->val;
        if(root->left == NULL && root->right==NULL){
            ans+=val;
        }
        solve(root->left,val);
        solve(root->right,val);
         
    }


    int sumNumbers(TreeNode* root) {
        ans = 0;
        int val = 0;
        solve(root,val); 
        return ans;
    }
};