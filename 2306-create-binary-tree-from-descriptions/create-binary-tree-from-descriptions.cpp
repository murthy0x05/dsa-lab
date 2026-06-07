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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int N = descriptions.size();

        unordered_map<int, TreeNode*> f;
        for (const vector<int>& desc: descriptions) {
            f[desc[1]] = new TreeNode(desc[1]);
        }

        TreeNode* root = nullptr;
        for (const vector<int>& desc: descriptions) {
            if (f.find(desc[0]) == f.end()) {
                root = new TreeNode(desc[0]);
                f[desc[0]] = root;
            }
            if (desc[2]) {
                f[desc[0]] -> left = f[desc[1]];
            } else {
                f[desc[0]] -> right = f[desc[1]];
            }
        }

        return root;
    }
};