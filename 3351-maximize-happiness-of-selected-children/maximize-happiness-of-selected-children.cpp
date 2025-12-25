class Solution {
    using ll = long long;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.rbegin(), rend(happiness));

        ll result = 0;
        for (int i = 0, ki = 0; i < k; i++) {
            if (ki >= happiness[i]) {
                return result;
            }
            result += happiness[i] - ki;
            ki++;
        }

        return result;
    }
};