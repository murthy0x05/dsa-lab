class Solution {
    fun countOperations(n1: Int, n2: Int): Int {
        var num1 = n1
        var num2 = n2
        var ops: Int = 0
        while (num1 > 0 && num2 > 0) {
            ops++;
            if (num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
        }

        return ops;
    }
}