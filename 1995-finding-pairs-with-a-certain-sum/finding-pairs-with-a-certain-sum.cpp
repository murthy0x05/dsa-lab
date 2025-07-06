class FindSumPairs {
    unordered_map<int, int> elements;
    vector<int> nums1, nums2;
    int n1, n2;
    inline int upper_bound(int target) {
        int low = 0, high = nums1.size() - 1;
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
public:
    inline FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        n1 = nums1.size(); n2 = nums2.size();
        for (int i = 0; i < n2; i++) {
            elements[nums2[i]]++;
        }
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        sort(this -> nums1.begin(), this -> nums1.end());
    }
    
    inline void add(int index, int val) {
        int prevVal = nums2[index];
        int newVal = prevVal + val;
        elements[prevVal] -= 1;
        elements[newVal] += 1;
        nums2[index] = newVal;
    }
    
    inline int count(int tot) {
        int result = 0, i = upper_bound(tot) - 1;
        while (i >= 0) {
            result += elements[tot - nums1[i]];
            i--;
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */