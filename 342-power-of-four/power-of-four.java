class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 &&
               1 == (Integer.bitCount(n)) &&
               0 == ((int)(Math.log(n) / Math.log(2)) & 1);
    }
}