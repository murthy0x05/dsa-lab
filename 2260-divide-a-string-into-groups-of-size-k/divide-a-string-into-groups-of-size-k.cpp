class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) {
            s.push_back(fill);
        }

        vector<string> result;
        for (int i = 0, len = s.size() / k; i < len; i++) {
            cout << i * k << " " << i * k + k << endl;
            result.push_back(s.substr(i * k, k));
        }

        return result;
    }
};