struct TrieNode {
    char data;
    int wordsEnded;
    TrieNode* child[26];
    TrieNode(char _data) {
        data = _data;
        wordsEnded = 0;
        fill(begin(child), end(child), nullptr);
    }
};

class Trie {
    TrieNode* root;
    #define psb push_back
    #define ppb pop_back
public:
    Trie() {
        root = new TrieNode('/');
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (const char& letter: word) {
            if (!curr -> child[letter - 'a']) {
                curr -> child[letter - 'a'] = new TrieNode(letter);
            }
            curr = curr -> child[letter - 'a'];
        }

        curr -> wordsEnded += 1;
    }
    void doDFS(auto& result, string& word, TrieNode* root, int& wordCount) {
        if (wordCount > 2) return ;
        if (root -> wordsEnded > 0) {
            result.back().psb(word);
            wordCount += 1;
            ///
        }

        for (int i = 0; i < 26; i++) {
            if (root -> child[i]) {
                word.psb(root -> child[i] -> data);
                doDFS(result, word, root -> child[i], wordCount);
                word.ppb();
            }
        }
    }
    vector<vector<string>> suggestedProducts(const string& searchWord) {
        vector<vector<string>> result;
        int n = searchWord.size();
        TrieNode* curr = root;
        string word = "";
        for (int i = 0; i < n; i++) {
            if (!curr -> child[searchWord[i] - 'a']) {
                while (i++ < n) result.psb({});
                return result;
            } else {
                word.psb(searchWord[i]);
                int wordCount = 0;
                result.psb({});
                doDFS(result, word, curr -> child[searchWord[i] - 'a'], wordCount);
                curr = curr -> child[searchWord[i] - 'a'];
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (const string& product: products) {
            trie.insert(product);
        }

        return trie.suggestedProducts(searchWord);
    }
};