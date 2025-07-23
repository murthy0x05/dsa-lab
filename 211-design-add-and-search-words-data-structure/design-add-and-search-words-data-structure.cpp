class TrieNode {
public:
    char val;
    int wordsIncluded, wordsEnded;
    TrieNode* child[26];
    TrieNode(char val) {
        this -> val = val;
        wordsIncluded = wordsEnded = 0;
    }
};

class WordDictionary {
    TrieNode* root;
    TrieNode* getTrieNode(char val) {
        TrieNode* node = new TrieNode(val);
        for (int i = 0; i < 26; i++) {
            node -> child[i] = nullptr;
        }

        return node;
    }
public:
    WordDictionary() {
        root = getTrieNode('/');
    }
    
    void addWord(string word) {
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
        return search(word, 0, root);
    }
    bool search(string& word, int i, TrieNode* curr) {
        int n = word.size();
        for (; i < n; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr -> child[j] != nullptr && search(word, i + 1, curr -> child[j])) {
                        return true;
                    }
                }
                return false;
            }
            if (curr -> child[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> child[word[i] - 'a'];
        }
        if (curr -> wordsEnded > 0 && i == n) {
            return true;
        } 
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */