class Solution {
public:
    vector<int> grayCode(int n) {
        function<vector<int>(int)> f = [&] (int n) {
            if (n == 1) {
                return vector<int>{0, 1};
            }

            vector<int> result;
            vector<int> temp = f(n - 1);
            for (int i = 0, len = temp.size(); i < len; i++) {
                result.push_back(temp[i] << 1);
            }
            for (int i = temp.size() - 1; i >= 0; i--) {
                result.push_back((temp[i] << 1) | 1);
            }

            return result;
        };

        return f(n);
    }
};