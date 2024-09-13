class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxi = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // Start with the root node at index 0

        while (!q.empty()) {
            long long size = q.size();
            long long left = q.front().second;  // Leftmost node index
            long long right = q.back().second;  // Rightmost node index
            maxi = max(maxi, right - left + 1);  // Update max width

            for (long long i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second - left;  // Normalize index
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * index + 1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }
        }

        return maxi;
    }
};
