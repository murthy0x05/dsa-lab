class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        unordered_map<char, int> map;
        map['N'] = 0; map['E'] = 1; map['W'] = 2; map['S'] = 3;
        int news[4] = {0};

        int maxDis = 0;
        for (int i = 0; i < n; i++) {
            news[map[s[i]]] += 1;
            int curr = std::abs(news[0] - news[3]) + std::abs(news[1] - news[2]);
            curr += std::min(i + 1 - curr, 2 * k);
            maxDis = std::max(maxDis, curr);
        }

        return maxDis;
    }
};