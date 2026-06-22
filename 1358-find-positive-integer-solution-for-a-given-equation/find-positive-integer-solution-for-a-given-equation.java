/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> result = new ArrayList<>();

        for (int x = 1, y = 1000; x <= 1000 && y >= 1; ) {
            int fxy = customfunction.f(x, y);

            if (fxy == z) {
                result.add(new ArrayList<>());
                result.get(result.size() - 1).add(x);
                result.get(result.size() - 1).add(y);
                x++; y--;
            } else if (fxy < z) {
                x++;
            } else {
                y--;
            }
        }

        return result;
    }
}