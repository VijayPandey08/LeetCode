/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        string tree2str(TreeNode *root)
        {

            if (root == NULL) // base case node mein kuch na bche toh empty string "" return kr do
            {
                return "";
            }
            string result = to_string(root->val); // ek result naam ki string banai aur tree ki root ki value usme daal di
            string Left = tree2str(root->left); // left se values leke aao
            string Right = tree2str(root->right); // right se values leke aao aur result m add kr do

            if (root->left == NULL && root->right == NULL) // agar dono taraf null ho jaae toh answer dedo
            {
                return result;
            }

            if (root->left == NULL)  // left side imp h uske lie empty parenthesis add krne pdenge : yeh observation se pta chala
            {
                return result + "()" + "(" + Right + ")";
            }

            if (root->right == NULL) // agar right side null h toh parenthesis ki koi zrurt nhi
            {
                return result + "(" + Left + ")";
            }

            return result + "(" + Left + ")" + "(" + Right + ")"; // ideal case jab left aur right dono side values h ...
        }
};