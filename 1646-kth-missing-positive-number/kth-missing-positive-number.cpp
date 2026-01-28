class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if ((k - (arr[n - 1] - n)) > 0) {
            return arr.back() + k - (arr.back() - n);
        }
        if (k < arr.front()) {
            return k;
        }
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (((arr[mid] - 1) - mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return arr[high] + k - ((arr[high] - 1) - high);
    }
};