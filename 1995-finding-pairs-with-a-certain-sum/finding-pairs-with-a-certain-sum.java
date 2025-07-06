class FindSumPairs {
    private int[] nums1, nums2;
    private int n1, n2;
    private HashMap<Integer, Integer> elements = new HashMap<>();
    public FindSumPairs(int[] nums1, int[] nums2) {
        n1 = nums1.length; n2 = nums2.length;
        this.nums1 = nums1;
        this.nums2 = nums2;
        for (int i = 0; i < n2; i++) {
            elements.put(nums2[i], elements.getOrDefault(nums2[i], 0) + 1);
        }
        Arrays.sort(nums1);
    }
    
    public void add(int index, int val) {
        int prevVal = nums2[index];
        int newVal = prevVal + val;
        elements.put(prevVal, elements.get(prevVal) - 1);
        elements.put(newVal, elements.getOrDefault(newVal, 0) + 1);
        nums2[index] = newVal;
    }
    
    private int upper_bound(int target) {
        int low = 0, high = n1 - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums1[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    public int count(int tot) {
        int result = 0, i = upper_bound(tot - 1) - 1;
        while (i >= 0) {
            result += elements.getOrDefault(tot - nums1[i], 0);
            i--;
        }

        return result;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */