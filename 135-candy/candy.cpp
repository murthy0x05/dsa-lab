class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;
        int up = 0, down = 0;
        int result = 1;
        while (i < n) {
            if (ratings[i] == ratings[i-1]) {
                i += 1;
                result += 1;
                continue;
            }
            up = 1;
            while (i < n && ratings[i - 1] < ratings[i]) {
                up += 1;
                result += up;
                i += 1;
            }
            down = 1;
            while (i < n && ratings[i - 1] > ratings[i]) {
                result += down;
                down += 1;
                i += 1;
            }
            if (up < down) {
                result += (down - up);
            }
        }

        return result;
    }
};