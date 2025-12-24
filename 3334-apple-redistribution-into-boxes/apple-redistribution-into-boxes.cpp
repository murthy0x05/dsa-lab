class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        
        int boxes = 0;
        for (int i = 0, m = capacity.size(), total = accumulate(apple.begin(), apple.end(), 0); total > 0 && i < m; total -= capacity[i++]) {
            boxes++;
        }

        return boxes;
    }
};