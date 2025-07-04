class Solution {
    public char kthCharacter(long k, int[] operations) {
        int n = operations.length;
        long val = k;
        int shifts = 0;

        while (val > 1) {
            int jumps = (int)Math.ceil(Math.log(val) / Math.log(2));
            val = val - (long)Math.pow(2, jumps - 1);
            shifts += operations[jumps - 1];
        }

        return (char)('a' + (int)(shifts % 26));
    }
}