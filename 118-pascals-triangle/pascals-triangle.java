class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> dp = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (0 == j || i == j) {
                    row.add(1);
                } else {
                    row.add(dp.get(i - 1).get(j - 1) + dp.get(i - 1).get(j));
                }
            }
            dp.add(row);
        }

        // dp code
        return dp;
    }
}