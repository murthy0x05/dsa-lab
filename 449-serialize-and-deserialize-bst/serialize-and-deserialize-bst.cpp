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

    // Encodes a tree to a single string.
    void doDFS(TreeNode* root, string& ans) {
        if (nullptr == root) {
            ans += '*';
        } else {
            ans += to_string(root -> val) + ',';
            doDFS(root -> left, ans);
            doDFS(root -> right, ans);
        }
    }
    string serialize(TreeNode* root) {
        string ans = "";
        doDFS(root, ans);

        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    int pos = 0;
    TreeNode* deserialize(string& data) {
        if ('*' == data[pos]) {
            pos++;
            return nullptr;
        } else {
            int start = pos, end = pos + 1;
            while (isdigit(data[end])) end++;
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
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;