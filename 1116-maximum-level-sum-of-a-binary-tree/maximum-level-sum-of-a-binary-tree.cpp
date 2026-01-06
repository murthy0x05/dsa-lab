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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        pair<int, int> result = make_pair(1, root -> val);
        int level = 1;
        while (!q.empty()) {
            int sum = 0;
            for (int i = 0, ls = q.size(); i < ls; i++) {
                sum += q.front() -> val;
                if (q.front() -> left)
                    q.push(q.front() -> left);
                if (q.front() -> right)
                    q.push(q.front() -> right);
                q.pop();
            }
            if (sum > result.second) {
                result.first = level;
                result.second = sum;
            }
            level++;
        }

        return result.first;
    }
};