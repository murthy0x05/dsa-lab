class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> seen;
        int start = 0, end = 1;
        seen[fruits[start]] = 1;

        int maxCollected = 1;
        while (end < n) {
            seen[fruits[end++]] += 1;

            while (seen.size() > 2) {
                seen[fruits[start]]--;
                if (0 == seen[fruits[start]]) {
                    seen.erase(fruits[start]);
                }
                start++;
            }

            maxCollected = max<int>(maxCollected, end - start);
        }

        return maxCollected;
    }
};