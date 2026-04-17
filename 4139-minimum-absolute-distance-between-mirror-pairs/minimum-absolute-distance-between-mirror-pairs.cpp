class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        const int N = nums.size();

        int minDist = INT_MAX;
        map<int, int> occ;
        for (int i = 0; i < N; i++) {
            if (occ.count(nums[i])) {
                minDist = min(minDist, i - occ[nums[i]]);
            }
            string num = to_string(nums[i]);
            reverse(num.begin(), num.end());
            int iNum = stoi(num);

            occ[iNum] = i;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};