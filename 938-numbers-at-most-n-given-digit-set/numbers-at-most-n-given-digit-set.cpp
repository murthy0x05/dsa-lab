class Solution {
    int lb(vector<string>& digits, int target) {
        int low = 0, high = digits.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (digits[mid][0] - '0' < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.size();
        int d = digits.size();

        int count = 0;
        for (int i = 1; i < len; i++) {
            count += pow(d, i);
        }

        for (int i = 0; i < len; i++) {
            int idx = lb(digits, s[i] - '0');
            count += idx * (pow(d, len - i - 1));
            if (idx >= d || digits[idx][0] != s[i]) {
                return count;
            }
        }

        // 33 34 35 36
        // 44 43 45 46
        // 55 53 54 56

        return count + 1;
    }
};