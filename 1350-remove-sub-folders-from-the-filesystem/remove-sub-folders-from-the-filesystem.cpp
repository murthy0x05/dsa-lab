#define psb push_back
#define ppb pop_back

struct TrieNode {
    char data;
    int fullstops = 0;
    TrieNode* child[27];
    TrieNode(char _data) {
        this -> data = _data;
        for (int i = 0; i < 27; i++) {
            child[i] = nullptr;
        }
    }
};
class Trie {
    TrieNode* root = nullptr;
public: 
    Trie() {
        root = new TrieNode('/');
    }
    void insert(string value) {
        int n = value.size();
        TrieNode* curr = root;
        for (int i = 1; i < n; i++) {
            if (value[i] == '/') {
                if (curr -> child[26] == nullptr)
                    curr -> child[26] = new TrieNode('/');
                curr = curr -> child[26];
            } else {
                if (curr -> child[value[i] - 'a'] == nullptr) {
                    curr -> child[value[i] - 'a'] = new TrieNode(value[i]);
                }
                curr = curr -> child[value[i] - 'a'];
            }
        }
        curr -> fullstops += 1;
    }
    void doDFS(string& path, vector<string>& result, TrieNode* node) {
        if (node -> fullstops > 0) {
            result.psb(path);
            for (int i = 0; i < 26; i++) {
                if (node -> child[i] != nullptr) {
                    path.psb(node -> child[i] -> data);
                    doDFS(path, result, node -> child[i]);
                    path.ppb();
                }
            }
            return ;
        }

        for (int i = 0; i < 27; i++) {
            if (node -> child[i] != nullptr) {
                path.psb(node -> child[i] -> data);
                doDFS(path, result, node -> child[i]);
                path.ppb();
            }
        } 
    }
    vector<string> solve(vector<string>& folder) {
        for (const string& path: folder) {
            this -> insert(path);
        }

        vector<string> result;
        string path = "/";
        for (int i = 0; i < 26; i++) {
            if (root -> child[i] != nullptr) {
                path.psb(root -> child[i] -> data);
                doDFS(path, result, root -> child[i]);
                path.ppb();
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        return trie.solve(folder);
    }
};