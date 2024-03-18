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
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(TreeNode* root, int targetSum, int sum){
            if(root==NULL){
            return ;
        }
  temp.push_back(root->val);
  sum+=root->val;
        if(root->left==NULL && root->right==NULL && sum==targetSum){
            ans.push_back(temp);
        }


        solve(root->left,targetSum,sum);
        solve(root->right,targetSum,sum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          int sum=0;
          solve(root,targetSum,sum);
          return ans;
        
    }
};