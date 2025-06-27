class Solution {
    private int countSubsequences(String seq, String subseq) {
        int n = seq.length(), m = subseq.length();
        int i = 0, j = 0, result = 0;
        while (i < n) {
            if (seq.charAt(i) == subseq.charAt(j)) {
                i += 1; j += 1;
            } else {
                i += 1;
            }
            if (j == m) {
                j = 0;
                result += 1;
            }
        }

        return result;
    }
    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length(), freq[] = new int[26];
        for (int i = 0; i < n; i++) {
            freq[s.charAt(i) - 'a'] += 1;
        }

        TreeSet<Character> validCharSet = new TreeSet<>();
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k)
                validCharSet.add((char)(i + 'a'));
        }

        Queue<String> q = new LinkedList<>();
        for (Character validChar: validCharSet)
            q.add(String.valueOf(validChar));
        String result = "";
        while (!q.isEmpty()) {
            String curr = q.poll();
            result = curr;
            for (Character validChar: validCharSet) {
                if (countSubsequences(s, curr + validChar) >= k) {
                    q.add(curr + validChar);
                }
            }
        }

        return result.toString();
    }
}