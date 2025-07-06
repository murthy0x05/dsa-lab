class FindSumPairs {
    unordered_map<int, unordered_set<int>> elements;
    vector<int> nums1, nums2;
    int n1, n2;
public:
    inline FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        n1 = nums1.size(); n2 = nums2.size();
        for (int i = 0; i < n2; i++) {
            elements[nums2[i]].insert(i);
        }
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        sort(this -> nums1.begin(), this -> nums1.end());
    }
    
    inline void add(int index, int val) {
        int prevVal = nums2[index];
        int newVal = prevVal + val;
        elements[prevVal].erase(index);
        elements[newVal].insert(index);
        nums2[index] = newVal;
    }
    
    inline int count(int tot) {
        int result = 0, i = n1 - 1;
        while (i >= 0 && nums1[i] >= tot) i--;
        while (i >= 0) {
            result += elements[tot - nums1[i]].size();
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