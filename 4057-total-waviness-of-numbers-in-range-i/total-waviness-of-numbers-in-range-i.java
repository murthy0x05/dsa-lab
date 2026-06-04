class Solution {

    private static final int[] prefix = new int[100001];
    private static boolean computed = false;

    public int totalWaviness(int num1, int num2) {
        
        if (!computed) {
            for (int i = 100; i <= 100000; i++) {
                prefix[i] = prefix[i - 1] + waviness(i);
            }
            computed = true;
        }

        return prefix[num2] - prefix[num1 - 1];
    }

    private int waviness(int n) {
        if (n < 100) return 0; 

        int count = 0;
        int right = n % 10;
        n /= 10;
        int current = n % 10;
        n /= 10;

        while (n > 0) {
            int left = n % 10;
            if ((current > left && current > right) || (current < left && current < right)) count++;
            right = current;
            current = left;
            n /= 10;
        }

        return count;
    }
}