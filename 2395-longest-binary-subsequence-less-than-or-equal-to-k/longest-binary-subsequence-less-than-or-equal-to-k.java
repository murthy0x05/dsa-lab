class Solution {
    public int longestSubsequence(String s, int k) {
        int n = s.length();
        int weight = 0, p = 0;
        
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ('1' == s.charAt(i)) {
                if (Math.pow(2, p) + weight <= k) {
                    result += 1;
                    weight += Math.pow(2, p);
                }
            } else {
                result += 1;
            }
            p += 1;
        }

        return result;
    }
}