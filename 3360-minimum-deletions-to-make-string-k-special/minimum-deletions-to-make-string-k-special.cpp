class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        int freqMap[26] = {0};
        for (int i = 0; i < n; i++) {
            freqMap[word[i] - 'a'] += 1;
        }
        std::sort(freqMap, freqMap + 26);

        int result = INT_MAX;
        int i = 0, deleted = 0;
        while (i < 26 && freqMap[i] == 0) i++;
        for (; i < 26; i++) {
            int deletions = deleted, j = 25;
            while (freqMap[j] - freqMap[i] > k) deletions += freqMap[j--] - freqMap[i] - k;
            result = std::min(result, deletions);
            deleted += freqMap[i];
        }

        return result;
    }
};