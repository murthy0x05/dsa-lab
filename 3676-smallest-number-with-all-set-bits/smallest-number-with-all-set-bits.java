class Solution {
    public int smallestNumber(int n) {
        int number = 0;
        long p = 1;
        while (n > 0) {
            number += p;
            n /= 2;
            p *= 2;
        }

        return number;
    }
}