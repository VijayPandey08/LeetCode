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
    vector<int> inorderTraversal(TreeNode* root) {
        // lets try morris traversal ..........
        vector<int> res;

        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }

            else {
                TreeNode* LeftChild = curr->left;

                while (LeftChild->right != NULL) {
                    LeftChild = LeftChild->right;
                }

                LeftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};