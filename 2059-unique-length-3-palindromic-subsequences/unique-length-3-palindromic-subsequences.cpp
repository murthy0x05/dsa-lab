class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> leftSet;
        unordered_map<char, int> rightMap;
        set<pair<char, char>> counterMap;
        for (char ch: s) {
            rightMap[ch] += 1;
        }
        int counter = 0;
        int mid = 0;
        while (mid < n) {
            rightMap[s[mid]]--;
            for (char ch: leftSet) {
                if (rightMap[ch] > 0) {
                    counterMap.insert(make_pair(s[mid], ch));
                }
            }
            leftSet.insert(s[mid]);
            mid++;
        }

        return counterMap.size();
    }
};