// struct Node {
//     Node* child[26];
//     int posIdx;
//     Node (int N) {
//         for (int i = 0; i < 26; i++) {
//             child[i] = nullptr;
//         }
//         posIdx = N;
//     }
// };
// class Trie {
//     int N;
// public:
//     Node* tree;
//     Trie(int _N): N(_N) {
//         tree = new Node(N);
//     }

//     void insert(int id, const string& word, const vector<int>& szs) {
//         Node* curr = tree;
//         for (int i = word.size() - 1; i >= 0; i--) {
//             char letter = word[i];
//             if (!curr -> child[letter - 'a']) {
//                 curr -> child[letter - 'a'] = new Node(N);
//             }
//             curr = curr -> child[letter - 'a'];
//             if (szs[curr -> posIdx] > szs[id]) {
//                 curr -> posIdx = id;
//             }
//         }
//     }
//     int query(const string& qword) {
//         Node* curr = tree;
//         int i = qword.size() - 1;
//         while (i >= 0 && curr -> child[qword[i] - 'a']) {
//             curr = curr -> child[qword[i] - 'a'];
//             i--;
//         }

//         return curr -> posIdx;
//     }
// };

// class Solution {
// public:
//     vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//         const int N = wordsContainer.size();
//         const int Q = wordsQuery.size();

//         vector<int> szs(N);
//         int smallestIdx = 0;
//         szs[0] = wordsContainer[0].size();
//         for (int i = 1; i < N; i++) {
//             szs[i] = wordsContainer[i].size();
//             if (szs[smallestIdx] > szs[i]) {
//                 smallestIdx = i;
//             }
//         }
//         szs.push_back(5001);

//         Trie* trie = new Trie(N);
//         trie -> tree -> posIdx = smallestIdx;

//         for (int i = 0; i < N; i++) {
//             trie -> insert(i, wordsContainer[i], szs);
//         }

//         vector<int> result;
//         for (const string& qword: wordsQuery) {
//             result.push_back(trie -> query(qword));
//         }

//         return result;
//     }
// };

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