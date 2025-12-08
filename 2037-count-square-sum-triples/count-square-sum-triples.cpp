class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int i = 1; i < n; i++) {
            int a2 = i * i;
            int low = i + 1, high = n;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                int c = sqrt(a2 + (mid * mid));
                if (c <= n) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            for (int j = i + 1; j < low; j++) {
                int sqr = sqrt((i * i) + (j * j));
                if (sqr <= n && sqr * sqr == ((i * i) + (j * j))) {
                    result += 2;
                    cout << i << ' ' << j << ' ' << sqr << endl;
                }
            }
        }

        return result;
    }
};