class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        for (int result = numBottles, empty = numBottles; numBottles >= 0;) {
            if (empty < numExchange) {
                return result;
            }

            empty -= numExchange - 1;
            result++;
            numExchange++;
        }

        return 0;
    }
}