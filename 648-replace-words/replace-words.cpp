struct TrieNode {
    char data;
    int wordsEnded;
    TrieNode* child[26];
    TrieNode(char _data) {
        data = _data;
        fill(child, child + 26, nullptr);
        wordsEnded = 0;
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
        for (const char& ch: word) {
            if (curr -> child[ch - 'a'] == nullptr) {
                curr -> child[ch - 'a'] = new TrieNode(ch);
            }
            curr = curr -> child[ch - 'a'];
        }

        curr -> wordsEnded += 1;
    }

    string getPrefix(const string& word) {
        TrieNode* curr = root; int n = word.size();
        int pos = 0; string prefix("");
        while (pos < n && curr -> child[word[pos] - 'a'] != nullptr) {
            prefix.psb(word[pos]);
            if (curr -> child[word[pos] - 'a'] -> wordsEnded > 0) {
                return prefix;
            }
            curr = curr -> child[word[pos] - 'a'];
            pos++;
        }

        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie; int slen = sentence.size();
        for (const string& word: dictionary) {
            trie.insert(word);
        }

        int start = 0, end = 0;
        string result = "";
        while (end < slen) {
            while (end < slen && sentence[end] != ' ') {
                end++;
            }
            string temp = trie.getPrefix(sentence.substr(start, end - start));
            if (temp.size()) {
                result += temp;
            } else {
                result += sentence.substr(start, end - start);
            }
            if (end != slen)
                result += ' ';
            start = end + 1;
            end++;
        }

        return result;
    }
};