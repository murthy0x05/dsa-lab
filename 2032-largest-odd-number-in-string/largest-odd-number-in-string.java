class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if (1 == ((num.charAt(i) - '0') & 1)) {
                return num.substring(0, i + 1);
            }
        }

        return new String();
    }
}