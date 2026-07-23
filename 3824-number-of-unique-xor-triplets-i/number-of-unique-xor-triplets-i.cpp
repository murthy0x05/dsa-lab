class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        size_t N = nums.size();
        
        if (N <= 2) {
            return N;
        } else {
            return 1 << (32 - __builtin_clz(N));
        }
    }
};