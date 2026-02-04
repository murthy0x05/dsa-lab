class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer; answer.reserve(n);
        for (const vector<int>& query: queries) {
            int ai = query[0], bi = query[1];
            unordered_map<int, int> seen;
            int len = 0;
            seen[ai] = len;
            while (ai > 1) {
                ai = ai / 2;
                len++;
                seen[ai] = len; 
            }
            len = 0;
            if (seen.count(bi)) {
                answer.push_back(len + seen[bi] + 1);
                continue;
            }
            while (bi > 1) {
                bi = bi / 2;
                len++;
                if (seen.count(bi)) {
                    answer.push_back(len + seen[bi] + 1);
                    break;
                }
            }
        }

        return answer;
    }
};