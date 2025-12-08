class Solution {
public:
    int countTriples(int n) {
        int result = 0;
        for (int c = 3; c <= n; c++) {
            int l = 1, r = c - 1;
            
            int needed = c * c;
            while (l < r) {
                int sum = l * l + r * r;
                if (needed == sum) {
                    result += 2;
                    l++; r--;
                } else if (sum < needed) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return result;
    }
};