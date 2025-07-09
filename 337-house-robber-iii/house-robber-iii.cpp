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
    unordered_map<TreeNode*, pair<int, int>> mem;
    int doDFS(TreeNode* root, bool canInclude = true) {
        if (!root) return 0;

        if (mem.count(root)) {
            if (canInclude == true && mem[root].first > 0) {
                return mem[root].first;
            }
            if (canInclude == false && mem[root].second > 0) {
                return mem[root].second;
            }
        }
        int include = 0;
        if (canInclude)
            include = root -> val + doDFS(root -> left, false) + doDFS(root -> right, false);
        int exclude = doDFS(root -> left) + doDFS(root -> right);

        if (!mem.count(root))
            mem[root] = make_pair(-1, -1);
        if (canInclude == true) {
            return mem[root].first = max(include, exclude);
        } else {
            return mem[root].second = max(include, exclude);
        }
    }
public:
    int rob(TreeNode* root) {
        return doDFS(root);
    }
};