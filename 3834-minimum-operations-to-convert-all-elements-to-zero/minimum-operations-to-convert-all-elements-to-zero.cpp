class Solution {
    typedef pair<int, int> pii;
public:
    int minOperations(vector<int>& nums) {
        stack<int> st; st.push(0);
        int n = nums.size();

        int ops = 0;
        for (int i = 0; i < n; i++) {
            while (st.top() > nums[i]) {
                st.pop();
                ops++;
            }
            if (st.top() != nums[i]) {
                st.push(nums[i]);
            }
        }

        return st.size() + ops - 1;
    }
};