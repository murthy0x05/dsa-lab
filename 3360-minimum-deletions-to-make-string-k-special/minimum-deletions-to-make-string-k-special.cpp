class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        unordered_map<char, int> freqMap;
        for (int i = 0; i < n; i++) {
            freqMap[word[i]] += 1;
        }

        int result = INT_MAX;
        for (auto [ch, minFreq]: freqMap) {
            int deletions = 0;
            for (auto [ch, freq]: freqMap) {
                if (freq < minFreq) {
                    deletions += freq;
                } else if (freq > minFreq + k) {
                    deletions += freq - minFreq - k;
                }
            }
            result = std::min(result, deletions);
        }

        return result;
    }
};