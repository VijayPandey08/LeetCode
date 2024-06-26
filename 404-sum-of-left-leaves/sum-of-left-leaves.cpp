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

int solve_1(TreeNode* curr, TreeNode* parent){
    if(curr==NULL){
        return 0;
    }
    if(curr->left==NULL && curr->right==NULL){
        if(parent!=NULL && parent->left==curr){
            return curr->val;
        }
    }
    int left = solve_1(curr->left,curr);
    int right = solve_1(curr->right,curr);
    return left + right;
}


int solve_2(TreeNode* root, bool isLeft){
    if(root==NULL){
        return 0;
    }
    if(root->left ==NULL && root->right==NULL && isLeft==true){
        return root->val;
    }
    return solve_2(root->left,true) + solve_2(root->right,false);

}
    int sumOfLeftLeaves(TreeNode* root) {
        // approach 1
        // return solve_1(root,NULL);

        //approach 2
        return solve_2(root,false);
    }
};