class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> freq_map;
        unordered_map<int, int> index_map;
        for (int i = 0; i < n; i++) {
            if (index_map.count(nums[i])) {
                freq_map[index_map[nums[i]]].second += 1;
            } else {
                freq_map.push_back(make_pair(nums[i], 1));
                index_map[nums[i]] = freq_map.size() - 1;
            }
        }

        for (auto& i: freq_map) {
            cout << i.first << " " << i.second << endl;
        }

        sort(freq_map.begin(), freq_map.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        });

        vector<int> result;
        for (auto& freq: freq_map) {
            for (int i = 0; i < freq.second; i++) {
                result.push_back(freq.first);
            }
        }

        return result;        
    }
};