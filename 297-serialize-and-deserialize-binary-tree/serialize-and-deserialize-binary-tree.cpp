/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    inline void doDFS(TreeNode* root, string& ans) {
        if (nullptr == root) {
            ans += '*';
        } else {
            ans += to_string(root -> val) + ',';
            doDFS(root -> left, ans);
            doDFS(root -> right, ans);
        }
    }

    // Encodes a tree to a single string.
    inline string serialize(TreeNode* root) {
        string ans = "";
        doDFS(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    int pos = 0;
    inline TreeNode* deserialize(const string& data) {
        if ('*' == data[pos]) {
            pos++;
            return nullptr;
        } else {
            int start = pos, end = pos + 1;
            while (data[end] >= '0' && data[end] <= '9') {
                end++;
            }
            int value = stoi(data.substr(start, end - start));
            TreeNode* node = new TreeNode(value);
            pos = end + 1;
            node -> left = deserialize(data);
            node -> right = deserialize(data);

            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));