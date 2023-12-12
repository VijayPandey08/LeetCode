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
int solve(TreeNode* root, int &ans, int height){
    if(root==NULL){
        return 0;
    }
    solve(root->left,ans,height+1);
    solve(root->right,ans,height+1);
    ans = max(ans,height);
    return ans;
}
    int maxDepth(TreeNode* root) {
        int ans=0;
        int height=1;
        int ans1=solve(root,ans,height);
        return ans1;
    }
};