// class TrieNode {
// public:
//     char val;
//     bool capital, small;
//     bool ended;
//     TrieNode* child[26];
//     TrieNode(char val) {
//         this -> val = val;
//         ended = false;
//         for (int i = 0; i < 26; i++) {
//             child[i] = nullptr;
//         }
//         capital = false;
//         small = false;
//     }
// };
// class Trie {
//     TrieNode* root;
//     unordered_set<char> vowels;
//     vector<int> v;
// public:
//     Trie() {
//         root = new TrieNode('/');
//         vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
//         v = {'a' - 'a', 'e' - 'a', 'i' - 'a', 'o' - 'a', 'u' - 'a'};
//     }
//     void insert(const string& word) {
//         TrieNode* curr = root;
//         for (char c: word) {
//             bool capital = c >= 'A' && c <= 'Z';
//             if (capital) c = c + ('a' - 'A');
//             if (curr -> child[c - 'a'] == nullptr) {
//                 curr -> child[c - 'a'] = new TrieNode(c);
//             }
//             curr = curr -> child[c - 'a'];
//             if (capital) {
//                 curr -> capital = true;
//             } else {
//                 curr -> small = true;
//             }
//         }
//         curr -> ended = true;
//     }
//     string getWord(const string& query) {
//         TrieNode* curr = root;
//         string word("");
//         for (char q: query) {
//             bool capital = q >= 'A' && q <= 'Z';
//             if (capital) q = q + ('a' - 'A');
//             if (curr -> child[q - 'a'] == nullptr) {
//                 if (vowels.count(q)) {
//                     int vj = -1;
//                     for (int vi: v) {
//                         if (curr -> child[vi]) {
//                             vj = vi;
//                             break;
//                         }
//                     }
//                     if (vj != -1) {
//                         curr = curr -> child[vj];
//                         word.push_back(curr -> capital ? ('A' + vj) : ('a' + vj));
//                     } else {
//                         return "";
//                     }
//                 } else {
//                     return "";
//                 }
//             } else {
//                 curr = curr -> child[q - 'a'];
//                 if (query == "KiTe") {
//                     cout << q << " " << capital << curr -> capital << endl;
//                 }
//                 if (capital && curr -> capital) {
//                     word.push_back(q - ('a' - 'A'));
//                     if (query == "KiTe") {
//                         cout << (char)(q - ('a' - 'A')) << endl;
//                     }
//                 } else {
//                     word.push_back(q);
//                 }
//             }
//         }
//         if (curr -> ended) {
//             return word;
//         } else {
//             return "";
//         }
//     }
// };

// class Solution {
// public:
//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         Trie trie;
//         for (string& word: wordlist) {
//             trie.insert(word);
//         }

//         vector<string> result(queries.size());
//         for (int i = 0, len = queries.size(); i < len; i++) {
//             result[i] = trie.getWord(queries[i]);
//         }

//         return result;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        for (string w : wordlist) {
            string lower = toLower(w);
            string devowel = deVowel(lower);
            if (!caseMap.count(lower)) caseMap[lower] = w;
            if (!vowelMap.count(devowel)) vowelMap[devowel] = w;
        }
        vector<string> result;
        for (string q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
            } else {
                string lower = toLower(q);
                string devowel = deVowel(lower);

                if (caseMap.count(lower)) result.push_back(caseMap[lower]);
                else if (vowelMap.count(devowel)) result.push_back(vowelMap[devowel]);
                else result.push_back("");
            }
        }
        return result;
    }
private:
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }
    string deVowel(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
        }
        return s;
    }
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
};