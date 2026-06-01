class Solution {
    public int minimumCost(int[] cost) {
        final int N = cost.length;

        cost = Arrays.stream(cost)
             .boxed()
             .sorted(Collections.reverseOrder())
             .mapToInt(i -> i)
             .toArray();
        int result = 0;
        for (int i = 0; i < N; i++) {
            if ((i + 1) % 3 != 0) {
                result += cost[i];
            }
        }

        return result;
    }
}