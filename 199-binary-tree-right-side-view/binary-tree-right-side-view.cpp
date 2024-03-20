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
vector<int> ans;


void dfs(TreeNode* root, int level=1){
    if(root==NULL) return;
if(ans.size()<level){
    ans.push_back(root->val);
}
    dfs(root->right,level+1);
    dfs(root->left,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        //bfs
        // if(root==NULL) return {};
        // queue<TreeNode*> q;
        // q.push(root);
        
        // while(q.size()>0){
        //     int a = q.size();
        //     for(int i=0; i<a; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(i==a-1){
        //             ans.push_back(node->val);
        //         }
        //        if(node->left) q.push(node->left);
        //        if(node->right) q.push(node->right);
        //     }
        // }
        // return ans;


        //dfs
        dfs(root);
        return ans;

    }
};