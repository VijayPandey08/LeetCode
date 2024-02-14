/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> ans;
        vector<int> temp;
    void solve(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL) return;

        if(sum+root->val == targetSum && root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }

        sum+=root->val;
        temp.push_back(root->val);
        solve(root->left,targetSum,sum);
        solve(root->right,targetSum,sum);
        temp.pop_back();
        
    }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        solve(root, targetSum, 0);
        return ans;
    }
};