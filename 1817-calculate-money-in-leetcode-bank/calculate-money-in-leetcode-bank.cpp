class Solution {
public:
    int totalMoney(int n) {
        int q = n / 7, rem = n % 7;
        
        int total = (28 * q) + 7 * ((q * (q - 1)) / 2) + rem * q + (rem * (rem + 1)) / 2; 

        return total;
    }
};