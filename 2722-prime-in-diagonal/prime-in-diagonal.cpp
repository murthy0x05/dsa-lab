class Solution {
    using ui = unsigned int;
    bool isPrime(ui n) {
        if (n < 2) {
            return false;
        }

        for (ui i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        ui n = nums.size();
        
        ui maxi = 0;
        for (ui i = 0; i < n; i++) {
            maxi = max<ui>({maxi, (ui)nums[i][i], (ui)nums[i][n - i - 1]});
        }

        ui maxPrime = 0;
        for (ui i = 0; i < n; i++) {
            if (isPrime((ui)nums[i][i]) && maxPrime < nums[i][i]) {
                maxPrime = nums[i][i];
            }
            if (isPrime((ui)nums[i][n - i - 1]) && maxPrime < nums[i][n - i - 1]) {
                maxPrime = nums[i][n - i - 1];
            }
        }

        return maxPrime;
    }
};