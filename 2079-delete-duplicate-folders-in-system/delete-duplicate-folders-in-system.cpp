struct TrieNode {
    string folder;
    bool remove = false;
    map<string, TrieNode*> child;
    inline TrieNode(string _folder) {
        this -> folder = _folder;
        this -> remove = false;
    }
};
class Trie {
    #define psb push_back
    #define ppb pop_back
public:
    TrieNode* root = nullptr;
    inline Trie() {
        root = new TrieNode("/");
    }

    inline void insert(const vector<string>& path) {
        TrieNode* curr = root;
        for (const string& folder: path) {
            if ((curr -> child).find(folder) == (curr -> child).end()) {
                curr -> child[folder] = new TrieNode(folder);
            }
            curr = curr -> child[folder];
        }
    }
    inline string mark_repeating(map<string, TrieNode*>& paths, TrieNode* root) {
        string subfolder("");
        for (auto& node: root -> child) {
            subfolder += mark_repeating(paths, node.second);
        }

        if (subfolder.size() != 0) {
            if (paths.find(subfolder) != paths.end()) {
                paths[subfolder] -> remove = true;
                root -> remove = true;
            } else {
                paths[subfolder] = root;
            }
        }

        return "[" + root -> folder + subfolder + "]";
    }
    inline bool doDFS(auto& result, auto& curr, TrieNode* root) {
        if (root -> remove) {
            return false;
        }

        for (auto& node: root -> child) {
            curr.psb(node.first);
            if (doDFS(result, curr, node.second)) {
                result.psb(curr);
            }
            curr.ppb();
        }

        return true;
    }
    inline vector<vector<string>> delete_and_return() {
        map<string, TrieNode*> paths;
        for (auto& [folder, node]: root -> child) {
            mark_repeating(paths, node);
        }

        vector<vector<string>> result;
        vector<string> curr;
        for (auto& node: root -> child) {
            curr.psb(node.first);
            if (doDFS(result, curr, node.second)) {
                result.psb(curr);
            }
            curr.ppb();
        }

        return result;
    }
};

class Solution {
public:
    inline vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;
        for (auto& path: paths) {
            trie.insert(path);
        }

        return trie.delete_and_return();
    }
};