class Solution {
    fun minCost(colors: String, neededTime: IntArray): Int {
        val n: Int = colors.length;

        var cost: Int = 0;
        for (i in 1 until n) {
            if (colors[i] == colors[i - 1]) {
                cost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return cost;
    }
}