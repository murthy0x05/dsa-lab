class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;

        for (final String op: operations) {
            if (op.charAt(0) == '-' || op.charAt(op.length() - 1) == '-') {
                x--;
            } else {
                x++;
            }
        }

        return x;
    }
}