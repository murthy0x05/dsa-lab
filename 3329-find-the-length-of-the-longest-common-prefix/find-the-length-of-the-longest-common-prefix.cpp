struct Node {
    vector<Node*> child;
    bool endsHere;
    Node () {
        child.resize(10, nullptr);
        endsHere = false;
    }
};
class Trie {
    Node* tree = nullptr;
public:
    Trie () {
        tree = new Node();
    }

    void insert(int _val) {
        string val = to_string(_val);

        Node* curr = tree;
        for (const char& digit: val) {
            if (!curr -> child[digit - '0']) {
                curr -> child[digit - '0'] = new Node();
            }
            curr = curr -> child[digit - '0'];
        }

        curr -> endsHere = true;
    }
    int maxPrefix(int _val) {
        string val = to_string(_val);

        Node* curr = tree;
        int len = 0;
        int i = 0;
        int N = val.size();
        while (i < N && curr -> child[val[i] - '0']) {
            curr = curr -> child[val[i] - '0'];
            len++;
            i++;
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for (const int& val: arr1) {
            trie.insert(val);
        }
        
        int longest = 0;
        for (const int& val: arr2) {
            longest = max(longest, trie.maxPrefix(val));
        }

        return longest;
    }
};