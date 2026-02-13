class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int N = nums.size();

        vector<int> subset;
        vector<vector<int>> subsets;
        sort(nums.begin(), nums.end());
        function<void(int)> f = [&] (int i) {
            if (i == N) {
                subsets.push_back(subset);
            } else {
                subset.push_back(nums[i]);
                f(i + 1);
                subset.pop_back();
                
                while (i + 1 < N && nums[i] == nums[i + 1]) i++;
                f(i + 1);
            }
        };
        f(0);

        return subsets;     
    }
};