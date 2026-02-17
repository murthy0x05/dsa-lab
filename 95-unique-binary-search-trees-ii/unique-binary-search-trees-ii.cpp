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
    vector<TreeNode*> generateTrees(int low, int high) {
        if (low > high) {
            return {nullptr};
        }

        vector<TreeNode*> trees;
        for (int i = low; i <= high; i++) {
            vector<TreeNode*> leftTrees = generateTrees(low, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, high);

            for (TreeNode* leftTree: leftTrees) {
                for (TreeNode* rightTree: rightTrees) {
                    TreeNode* node = new TreeNode(i);
                    node -> left = leftTree;
                    node -> right = rightTree;

                    trees.push_back(node);
                }
            }
        }

        return trees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};