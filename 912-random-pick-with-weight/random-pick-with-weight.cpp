class Solution {
    vector<int> ps;
public:
    Solution(vector<int>& w) {
        ps.reserve(w.size());
        ps.resize(w.size());

        ps[0] = w[0];
        for (int i = 1, n = w.size(); i < n; i++) {
            ps[i] = w[i] + ps[i - 1];
        }
    }
    
    int pickIndex() {
        int val = rand() % ps.back();
        return upper_bound(ps.begin(), ps.end(), val) - ps.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */