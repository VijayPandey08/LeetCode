/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> &temp) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        // vector<int> temp;
        while (!q.empty()) {
            TreeNode* test = q.front();
            q.pop();
         if(test!=NULL){
                temp.push_back(test->val);
                if (test->left != NULL)
                    q.push(test->left);
                if (test->right != NULL)
                    q.push(test->right);
            
         }
         else if(test == NULL){
                if (!q.empty()) {
                    q.push(NULL);
                    ans.push_back(temp);
                    temp.erase(temp.begin(), temp.end());
                } else {
                    ans.push_back(temp);
                    break;
                }
         }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;

        if(root==NULL) return ans;

        solve(root, ans, temp);

        return ans;
    }
};