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
void solve(TreeNode* root, int &ans, int height){
    if(root==NULL){
        return;
    }
    solve(root->left,ans,height+1);
    solve(root->right,ans,height+1);
    ans = max(ans,height);
}
    int maxDepth(TreeNode* root) {
        int ans=0;
        int height=1;
        solve(root,ans,height);
        return ans;
    }
};