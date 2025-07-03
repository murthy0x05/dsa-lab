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
private:
    TreeNode* treeRoot = nullptr;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum, int currSum = 0) {
        if (!treeRoot) this -> treeRoot = root;
        if (!root) return {};
        if (!root -> left && !root -> right) {
            if (targetSum == (currSum + root -> val)) {
                return {{root -> val}};
            } else {
                return {};
            }
        }

        vector<vector<int>> leftTree = pathSum(root -> left, targetSum, currSum + root -> val);
        vector<vector<int>> rightTree = pathSum(root -> right, targetSum, currSum + root -> val);

        if (leftTree.size() > 0) {
            for (vector<int>& tree: leftTree) {
                tree.push_back(root -> val);
            }
        }

        if (rightTree.size() > 0) {
            for (vector<int>& tree: rightTree) {
                tree.push_back(root -> val);
            }
        }

        vector<vector<int>> result;
        for (vector<int> tree: leftTree) {
            if (tree.size()) result.push_back(tree);
        }
        for (vector<int> tree: rightTree) {
            if (tree.size()) result.push_back(tree);
        }

        if (root == treeRoot) {
            for (vector<int>& list: result) {
                int start = 0, end = list.size() - 1;
                while (start < end) {
                    list[start] = list[end] + list[start];
                    list[end] = list[start] - list[end];
                    list[start] = list[start] - list[end];
                    start += 1; end -= 1;
                }
            }
        }

        return result;
    }
};

// class Solution {
//     vector<vector<int>> solve(TreeNode* root, vector<int>& path, int currSum, int& targetSum) {
//         currSum += root -> val;
//         path.push_back(root -> val);
//         vector<vector<int>> result;
//         if (!root -> left && !root -> right) {
//             if (targetSum == currSum) {
//                 result.push_back(path);
//             }
//         }
//         if (root -> left) {
//             vector<vector<int>> leftResult = solve(root -> left, path, currSum, targetSum);
//         }
//         if (root -> right) {
//             vector<vector<int> rightResult = solve(root -> right, path, currSum, targetSum);
//         }
//         for (vector<int>& tree: leftResult) {

//         }
//     }
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum, int currSum = 0) {
//         if (!root) {
//             return {};
//         }
//         vector<int> path;
//         return solve(root, path, 0, targetSum);
//     }
// };