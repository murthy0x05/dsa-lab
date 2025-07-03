// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         if (n <= 1) return strs[0];
//         string prefix = strs[0];

//         for (int i = 1; i < n; i++) {
//             int s = 0;
//             while (s < prefix.size() && s < strs[i].size() && prefix[s] == strs[i][s]) {
//                 s++;
//             }
//             prefix = strs[i].substr(0, s);
//         }

//         return prefix;
//     }
// };

class TrieNode {
public:
    char val;
    int wordsEnded;
    int wordsIncluded;
    TrieNode* child[26];
    TrieNode(char val) {
        this -> val = val;
        wordsEnded = 0;
        wordsIncluded = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root = nullptr;
public:
    Trie() {
        root = new TrieNode('/');
    }
    void insert(string word)  {
        int n = word.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[word[i] - 'a'] == nullptr) {
                curr -> child[word[i] - 'a'] = new TrieNode(word[i]);
            }
            curr = curr -> child[word[i] - 'a'];
            curr -> wordsIncluded += 1;
        }
        curr -> wordsEnded += 1;
    }
    bool startsWith(const string& query) {
        int n = query.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[query[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> child[query[i] - 'a'];
        }

        return (curr -> wordsIncluded > 0);
    }
    bool search(const string& query) {
        int n = query.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr -> child[query[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> child[query[i] - 'a'];
        }
        
        return (curr -> wordsEnded > 0);
    }
    string longestCommonPrefix(string temp, int len) {
        int n = temp.size();
        TrieNode* curr = root;
        string result("");
        for (int i = 0; i < n; i++) {
            if (curr -> child[temp[i] - 'a'] -> wordsIncluded != len) {
                break;
            }
            result.push_back(curr -> child[temp[i] - 'a'] -> val);
            curr = curr -> child[temp[i] - 'a'];
        }

        return result;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        for (const string& str: strs) {
            trie -> insert(str);
        }
        return trie -> longestCommonPrefix(strs[0], strs.size());
    }
};