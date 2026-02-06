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
    using pll = pair<long, long>;
    // first = Max value
    // second = min value
    bool valid = true;
    pll dfs(TreeNode* root) {
        if (!root) {
            return make_pair(LONG_MIN, LONG_MAX);
        }

        pll fromLeft = dfs(root -> left);
        pll fromRight = dfs(root -> right);

        if ((fromLeft.first >= root -> val) || (fromRight.second <= root -> val)) {
            valid = false;
        }

        return make_pair(max({fromLeft.first, 0L + root -> val, fromRight.first}),
                         min({fromLeft.second, 0L + root -> val, fromRight.second}));
    }
public:
    bool isValidBST(TreeNode* root) {
        dfs(root);

        return valid;
    }
};