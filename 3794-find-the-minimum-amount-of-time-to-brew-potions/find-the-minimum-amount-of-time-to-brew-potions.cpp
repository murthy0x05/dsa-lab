class Solution {
    using ll = long long;
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<ll> time(n + 1, 0);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; i++) {
                time[i + 1] = max(time[i + 1], time[i]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; i--) {
                time[i] = time[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        
        return time[n];
    }
};