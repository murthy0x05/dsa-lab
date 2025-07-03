class TrieNode {
public:
    char val;
    int wordsIncluded;
    int wordsEnded;
    TrieNode* child[26];
    TrieNode(char val) {
        this -> val = val;
        wordsIncluded = 0;
        wordsEnded = 0;
    }
};

class Trie {
private:
    TrieNode* root = nullptr;
    TrieNode* getTrieNode(char val) {
        TrieNode* node = new TrieNode(val);
        for (int i = 0; i < 26; i++) {
            node -> child[i] = nullptr;
        }
        return node;
    }
public:
    Trie() {
        root = getTrieNode('/');
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[word[i] - 'a'] == nullptr) {
                curr -> child[word[i] - 'a'] = getTrieNode(word[i]);
            }
            curr = curr -> child[word[i] - 'a'];
            curr -> wordsIncluded += 1;
        }
        curr -> wordsEnded += 1;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> child[word[i] - 'a'];
        }
        return curr -> wordsEnded > 0;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> child[prefix[i] - 'a'];
        }
        return curr -> wordsIncluded > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */