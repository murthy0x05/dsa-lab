class Solution {
    fun numberOfBeams(bank: Array<String>): Int {
        val r: Int = bank.size
        val c: Int = bank[0].length

        var i = 0
        var prev = 0
        do {
            for (j in 0 until c) {
                if (bank[i][j] == '1') {
                    prev++
                }
            }
            i++
        } while (i < r && prev == 0);

        var result: Int = 0
        while (i < r) {
            var curr = 0
            do {
                for (j in 0 until c) {
                    if (bank[i][j] == '1') {
                        curr++
                    }
                }
                i++
            } while (i < r && curr == 0);

            result += curr * prev
            prev = curr
        }

        return result
    }
}