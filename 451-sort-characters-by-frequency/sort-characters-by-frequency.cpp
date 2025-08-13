class Solution {
    #define pci pair<char, int>
public:
    inline string frequencySort(string s) {
        vector<pci> freqMap(256);
        for (int i = 0; i < 256; i++) {
            freqMap[i].first = (char)i;
            freqMap[i].second = 0;
        }

        for (const char& c: s) {
            freqMap[c].second++;
        }

        sort(freqMap.begin(), freqMap.end(), [](const pci& a, const pci& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
        });

        string result("");
        for (auto& [c, freq]: freqMap) {
            while (freq--) result.push_back(c);
        }

        return result;
    }
};