class Solution {
    using ui = unsigned int;
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max<int>({maxi, nums[i][i], nums[i][n - i - 1]});
        }

        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= maxi; i++) {
            if (isPrime[i]) {
                for (ui j = i * (ui)i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int maxPrime = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[nums[i][i]] && maxPrime < nums[i][i]) {
                maxPrime = nums[i][i];
                cout << i << endl;
            }
            if (isPrime[nums[i][n - i - 1]] && maxPrime < nums[i][n - i - 1]) {
                maxPrime = nums[i][n - i - 1];
            }
        }

        return maxPrime;
    }
};