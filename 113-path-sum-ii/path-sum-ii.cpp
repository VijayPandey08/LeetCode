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
        
    
    void solve(TreeNode *root, int targetSum, int sum,vector<vector < int>> &ans,vector<int> temp)
    {
        if (root == NULL) return; //dfs


        // if(sum+root->val == targetSum && root->left==NULL && root->right==NULL){  // according to question
        //     temp.push_back(root->val);
        //     ans.push_back(temp);
        //     temp.pop_back();
        //     return ;
        // }

        // sum+=root->val;             
        // temp.push_back(root->val); // backtrack (call k pehle)
        // solve(root->left,targetSum,sum); //dfs
        // solve(root->right,targetSum,sum); //dfs
        // temp.pop_back(); // backtrack (call k baad)

        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
                return;
            }
        }
        solve(root->left, targetSum,  sum,ans,temp);
        solve(root->right, targetSum,  sum,ans,temp);
    }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        int sum=0;
        solve(root, targetSum, sum,ans,temp);
        return ans;
    }
};