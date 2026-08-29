class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> indexMap(n);
        for (int i = 0; i < n; i++) {
            indexMap[i] = make_pair(nums[i], i);
        }

        sort(indexMap.begin(), indexMap.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else return a.second < b.second;
        });
        
        priority_queue<int, vector<int>, greater<int>> numHeap;
        priority_queue<int, vector<int>, greater<int>> indexHeap;
        numHeap.push(indexMap[0].first);
        indexHeap.push(indexMap[0].second);
        for (int i = 1; i <= n; i++) {
            if (i == n || abs(indexMap[i-1].first - indexMap[i].first) > limit) {
                while (!numHeap.empty()) {
                    nums[indexHeap.top()] = numHeap.top();
                    indexHeap.pop();
                    numHeap.pop();
                }
                if (i == n) return nums;
            }
            numHeap.push(indexMap[i].first);
            indexHeap.push(indexMap[i].second);
        }

        return nums;
    }
};