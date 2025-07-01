class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> mStack; mStack.push(nums[n - 1]); // Monotonic Stack: Decreasing

        vector<int> nge(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            while (!mStack.empty() && mStack.top() <= nums[i]) {
                mStack.pop();
            }
            mStack.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!mStack.empty() && mStack.top() <= nums[i]) {
                mStack.pop();
            }
            if (!mStack.empty()) {
                nge[i] = mStack.top();
            }
            mStack.push(nums[i]);
        }

        return nge;    
    }
};