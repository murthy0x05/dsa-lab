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
    void doDFS(TreeNode* node, auto& nodes, int x, int y) {
        if (!node) {
            return ;
        }
        nodes.push_back({node, {x, y}});
        if (node -> left) {
            doDFS(node -> left, nodes, x + 1, y - 1);
        }
        if (node -> right) {
            doDFS(node -> right, nodes, x + 1, y + 1);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<TreeNode*, pair<int, int>>> nodes;
        doDFS(root, nodes, 0, 0);
        sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b) {
            if (a.second.second != b.second.second) {
                return a.second.second < b.second.second;
            } else {
                if (a.second.first != b.second.first) {
                    return a.second.first < b.second.first;
                } else {
                    return a.first -> val < b.first -> val;
                }
            }
        });
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i].first -> val << ": " << nodes[i].second.first << " " << nodes[i].second.second << endl;
        }
        vector<vector<int>> result;
        int i = 0, n = nodes.size();
        while (i < n) {
            result.push_back({nodes[i].first -> val}); i++;
            while (i < n && nodes[i - 1].second.second == nodes[i].second.second) {
                result.back().push_back(nodes[i].first -> val);
                i++;
            }
        }

        return result;
    }
};