class Solution {
    private List<List<Integer>> dp = null;
    private int solve(int i, int j, int[] freqMap, int k) {
        if (i == j || freqMap[j] - freqMap[i] <= k) return 0;

        if (dp.get(i).get(j) != -1) return dp.get(i).get(j);
        dp.get(i).set(j, Math.min(freqMap[i] + solve(i + 1, j, freqMap, k), freqMap[j] - freqMap[i] - k + solve(i, j - 1, freqMap, k)));

        return dp.get(i).get(j);
    }
    public int minimumDeletions(String word, int k) {
        int freqMap[] = new int[26], n = word.length();
        Arrays.fill(freqMap, 0);
        for (int i = 0; i < n; i++) freqMap[word.charAt(i) - 'a']++;
        Arrays.sort(freqMap);
        dp = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            dp.add(new ArrayList<>());
            for (int j = 0; j < 26; j++) {
                dp.get(i).add(-1);
            }
        }

        return solve(0, 25, freqMap, k);
    }
}