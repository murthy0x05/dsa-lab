class Solution {
public:
    inline vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) {
            s.push_back(fill);
        }

        vector<string> result;
        for (int i = 0, len = s.size() / k; i < len; i++) {
            result.push_back(s.substr(i * k, k));
        }

        return result;
    }
};