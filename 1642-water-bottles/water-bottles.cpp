class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0,
            empty = 0;

        for (int empty = 0; numBottles > 0; empty %= numExchange) {
            result += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }

        return result;
    }
};