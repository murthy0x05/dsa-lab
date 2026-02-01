class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int> pq;
        for (int i = 1; i < n; i++) {
            if (pq.size() == 2) {
                if (pq.top() > nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            } else {
                pq.push(nums[i]);
            }
        }

        int result = nums[0] + pq.top(); pq.pop();
        return result + pq.top();
    }
};