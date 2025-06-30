class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nge(n1);
        unordered_map<int, int> map;
        for (int i = 0; i < n1; i++) {
            map[nums1[i]] = i;
        }
        stack<int> st;
        if (map.count(nums2[n2 - 1])) {
            nge[map[nums2[n2 - 1]]] = -1;
        }
        st.push(nums2[n2 - 1]);
        for (int i = n2 - 2; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (map.find(nums2[i]) != map.end()) {
                nge[map[nums2[i]]] = st.empty() ? -1 : st.top();
            }
            st.push(nums2[i]);
        }

        return nge;
    }
};