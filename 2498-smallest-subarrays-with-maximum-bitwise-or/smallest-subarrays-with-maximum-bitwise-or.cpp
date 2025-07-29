class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int max_ele = *max_element(nums.begin(), nums.end());
        int bit_count = (max_ele == 0) ? 1 : (int)log2(max_ele) + 1;

        vector<int> answer(n, 1),
                    nsb(bit_count, n); // next set bit

        for (int i = n - 1; i >= 0; i--) {
            int fsb = i;
            for (int j = 0; j < bit_count; j++) {
                if (nums[i] & (1 << j)) {
                    nsb[j] = i;
                } else if (nsb[j] != n) {
                    fsb = max(fsb, nsb[j]);
                }
            }
            answer[i] = fsb - i + 1;
        }

        return answer;
    }
};