class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = 0,
            empty = 0;

        for (int result = 0, empty = 0; numBottles >= 0; ) {
            result += numBottles;
            empty += numBottles;
            if (empty < numExchange) {
                return result;
            }

            for (numBottles = 0; empty >= numExchange;) {
                empty -= numExchange;
                numBottles++;
                numExchange++;
            }
        }

        return 0;
    }
};