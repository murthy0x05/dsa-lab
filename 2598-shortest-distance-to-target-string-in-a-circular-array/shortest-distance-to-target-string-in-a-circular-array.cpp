class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const int N = words.size();

        int dist = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (target == words[i]) {
                dist = min({dist, abs(i - startIndex), startIndex + N - i, N - startIndex + i});
            }
        }

        return dist == INT_MAX ? -1 : dist;
    }
};