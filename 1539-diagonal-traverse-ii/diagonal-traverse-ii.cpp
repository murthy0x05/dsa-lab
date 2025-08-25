class Solution {
    struct state {
        int val, i, j;
        state(int v, int i, int j) : val(v), i(i), j(j) {}
    };
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int r = nums.size();

        auto cmp = [](const state& a, const state& b) {
            if ((a.i + a.j) != (b.i + b.j)) {
                return (a.i + a.j) > (b.i + b.j);
            } else {
                return a.i < b.i;
            }
        };
        priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < r; i++) {
            for (int j = 0, c = nums[i].size(); j < c; j++) {
                // Return Value Optimization(RVO)
                pq.push(state(nums[i][j], i, j));
            }
        }

        vector<int> flatend;
        while (!pq.empty()) {
            flatend.push_back(pq.top().val);
            pq.pop();
        }



        return flatend;

    }
};