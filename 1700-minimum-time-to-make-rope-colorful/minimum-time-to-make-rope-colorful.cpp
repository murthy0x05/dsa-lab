class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        neededTime.push_back(10001);
        colors.push_back('@');
        int n = neededTime.size();

        int cost = 0;
        for (int i = 1, sum = neededTime[0]; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            } else {
                cost += sum - neededTime[i - 1];
                sum = neededTime[i];
            }
        }

        return cost;
    }
};