struct Node {
    int child[26];
    int posIdx;

    Node(int idx = -1) {
        memset(child, -1, sizeof(child));
        posIdx = idx;
    }
};

class Trie {
public:
    vector<Node> trie;

    Trie(int smallestIdx) {
        trie.emplace_back(smallestIdx);
    }

    void insert(int id, const string& word, const vector<int>& szs) {
        int curr = 0;

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[curr].child[c] == -1) {
                trie[curr].child[c] = trie.size();
                trie.emplace_back(id);
            }

            curr = trie[curr].child[c];

            if (szs[id] < szs[trie[curr].posIdx]) {
                trie[curr].posIdx = id;
            }
        }
    }

    int query(const string& word) {
        int curr = 0;

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[curr].child[c] == -1) {
                break;
            }

            curr = trie[curr].child[c];
        }

        return trie[curr].posIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        
        int n = wordsContainer.size();

        vector<int> szs(n);

        int smallestIdx = 0;

        for (int i = 0; i < n; i++) {
            szs[i] = wordsContainer[i].size();

            if (szs[i] < szs[smallestIdx]) {
                smallestIdx = i;
            }
        }

        Trie trie(smallestIdx);

        for (int i = 0; i < n; i++) {
            trie.insert(i, wordsContainer[i], szs);
        }

        vector<int> ans;

        for (const string& q : wordsQuery) {
            ans.push_back(trie.query(q));
        }

        return ans;
    }
};