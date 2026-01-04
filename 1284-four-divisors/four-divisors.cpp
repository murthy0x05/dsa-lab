class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 3) continue;
            int factors = 2, sum = 1 + nums[i];
            for (int j = 2, root = sqrt(nums[i]); j <= root; j++) {
                if (nums[i] % j == 0) {
                    if (factors == 4) {
                        factors += 2;
                        break;
                    } else if (j * j == nums[i]) {
                        factors += 1;
                        break;
                    } else {
                        factors += 2;
                        sum += j + (nums[i] / j);
                    }
                }
            }
            total += (factors == 4) * (sum);
            cout << i << ' ' << total << endl;
        }

        return total;
    }
};