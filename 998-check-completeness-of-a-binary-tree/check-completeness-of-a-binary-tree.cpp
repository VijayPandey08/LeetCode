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


bool solve(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    bool nullFound=false;
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        if(front==NULL){
            nullFound=true;
        }
        else{
            if(nullFound){
                return false;
            }
            q.push(front->left);
            q.push(front->right);
        }
    }
        return true;
}
    bool isCompleteTree(TreeNode* root) {
        // approach simple hein ki koi bhi non null node se pehle agar null node aagyi toh complete tree nahi hoga..
        // intution yeh hein ki jitne nodes available h vo barabar hone chaihye total nodes ke jitne level order traverse krte waqt milte h
        return solve(root);
    }
};