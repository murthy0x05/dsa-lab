class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freqMap;
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]] += 1;
        }

        int luckyInteger = -1;
        for (unordered_map<int, int>::iterator itr = freqMap.begin(); itr != freqMap.end(); itr++) {
            if ((*itr).first == (*itr).second) {
                luckyInteger = max(luckyInteger, (*itr).first);
            }
        }

        return luckyInteger;
    }
};