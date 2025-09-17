class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0, len = 0, sum = 0; i < 2 * n - 1; i++) {
            int idx = i % n;
            if ((sum += gas[idx] - cost[idx]) >= 0) {
                if (++len == n) return (idx + 1) % n;
            } else {
                len = sum = 0;
            }
        }

        return -1;
    }
};