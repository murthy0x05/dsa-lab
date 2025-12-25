class Solution {
    using ll = long long;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.rbegin(), happiness.rend());

        ll result = 0LL;
        for (int i = 0, ki = 0; i < k; i++) {
            if (ki >= happiness[i]) {
                break;
            }
            result += happiness[i] - ki;
            ki++;
        }

        return result;
    }
};