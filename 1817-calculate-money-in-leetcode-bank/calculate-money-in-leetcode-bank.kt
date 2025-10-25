class Solution {
    fun totalMoney(n: Int): Int {
        val (q: Int, rem: Int) = Pair(n / 7, n % 7)
        
        val total: Int = (28 * q) + 7 * ((q * (q - 1)) / 2) + rem * q + (rem * (rem + 1)) / 2; 

        return total;
    }
}