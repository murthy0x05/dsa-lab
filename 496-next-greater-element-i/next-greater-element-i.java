class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n1; i++) {
            map.put(nums1[i], i);
        }
        Stack<Integer> st = new Stack<>();
        int[] nge = new int[n1];
        if (map.containsKey(nums2[n2 - 1])) {
            nge[map.get(nums2[n2 - 1])] = -1;
        }
        st.push(nums2[n2 - 1]);
        for (int i = n2 - 2; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= nums2[i]) {
                st.pop();
            }
            if (map.containsKey(nums2[i])) {
                nge[map.get(nums2[i])] = st.isEmpty() ? -1 : st.peek();
            }
            st.push(nums2[i]);
        }

        return nge;
    }
}