/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL) return NULL;


        // case1: p and q both comes in left subtree
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }


        // case2: p and q both come in right subtree
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }


        //case3: 
        // p is in left subtree and q is in right subtree
        if(p->val<root->val && q->val>root->val){
            return root;
        }


//case4: 
        // p is in right subtree and q is in left subtree
           if(p->val>root->val && q->val<root->val){
            return root;
        }
        return root;

    }
};