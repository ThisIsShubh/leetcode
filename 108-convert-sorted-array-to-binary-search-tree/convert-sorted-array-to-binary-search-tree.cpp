/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    // Make buildBST an inline private lambda to reduce call overhead
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        const int n = nums.size();

        std::function<TreeNode*(int, int)> buildBST = [&](int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            // Use unsigned right shift instead of division for speed
            int mid = (left + right) >> 1;

            // Allocate node
            TreeNode* node = new TreeNode(nums[mid]);

            // Tail-recursion friendly order
            node->left = buildBST(left, mid - 1);
            node->right = buildBST(mid + 1, right);
            return node;
        };

        return buildBST(0, n - 1);
    }
};
