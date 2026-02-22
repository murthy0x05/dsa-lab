class SummaryRanges {
    vector<bool> seen;
    int MAX_LEN = 1e4 + 1;
public:
    SummaryRanges() {
        seen.resize(MAX_LEN, false);
    }
    
    void addNum(int value) {
        seen[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int l = 0, r = 0;
        while (r < MAX_LEN) {
            while (l < MAX_LEN && !seen[l]) l++;
            if (l < MAX_LEN) {
                r = l;
                while (r < MAX_LEN && seen[r]) r++;
                intervals.push_back({l, r-1});
                l = r;
            }
            r = l;
        }

        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */