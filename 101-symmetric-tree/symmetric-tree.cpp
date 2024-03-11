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
bool isSame(TreeNode* p, TreeNode* q){
    
    if(p!=NULL && q==NULL  || q!=NULL && p==NULL) return false;
    if(p==NULL && q==NULL) return true;
    if(p->val != q->val) return false;
    if(p!=NULL){
        return (isSame(p->left,q->right) & isSame(p->right,q->left));
    }
    else{
        return true;
    }
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSame(root->left,root->right);
    }
};