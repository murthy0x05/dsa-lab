class Solution {
    int upper_bound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
public:
    bool isSubsequence(const string& s, const string& t) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }

        int currPos = -1;
        for (const char& c: s) {
            int idx = upper_bound(pos[c - 'a'], currPos);
            if (idx < pos[c - 'a'].size()) {
                currPos = pos[c - 'a'][idx];
            } else {
                return false;
            }
        }

        return true;
    }
};