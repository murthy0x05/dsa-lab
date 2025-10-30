class Solution {
    fun minNumberOperations(target: IntArray): Int {
        var ops: Int = target[0]
        for (i in 1 until target.size) {
            if (target[i] > target[i - 1]) {
                ops += target[i] - target[i - 1];
            }
        }

        return ops;
    }
}