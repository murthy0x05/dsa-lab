class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> seen;
        int start = 0, end = 1;
        seen[fruits[start]] = 1;

        int maxCollected = 1;
        while (end < n) {
            while (end < n && seen.size() < 3) {
                seen[fruits[end]] += 1;
                end++;
            }

            if (seen.size() < 3) {
                maxCollected = max<int>(maxCollected, end - start);
            } else {
                maxCollected = max<int>(maxCollected, end - start - 1);
            }
            seen[fruits[start]] -= 1;
            if (0 == seen[fruits[start]]) {
                seen.erase(fruits[start]);
            }
            start++;
        }

        return maxCollected;
    }
};