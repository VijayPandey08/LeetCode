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
    map<long long,long long> m;
    int ans;

    void solve(TreeNode* root, int targetSum,long long sum){
        if(root==NULL) return;
        sum+=root->val;
        if(m.find(sum-targetSum)!=m.end()){
            ans+=m[sum-targetSum];
        }
        m[sum]++;
        solve(root->left,targetSum,sum);
        solve(root->right,targetSum,sum);
        m[sum]--;


    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        m[0]++;
        solve(root,targetSum,0ll);
        return ans;
    }
};