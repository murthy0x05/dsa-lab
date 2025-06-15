class Solution {
    public final int maxDiff(int num) {
        int size = 1, temp = num;
        int lowMSD = Integer.MAX_VALUE;
        int highMSD = Integer.MIN_VALUE;
        int minVal, maxVal;
        while (temp / 10 > 0) {
            if (temp % 10 != 9)
                lowMSD = temp % 10;
            if (temp % 10 != 0 && temp % 10 != 1)
                highMSD = temp % 10;
            size += 1;
            temp /= 10;
        }

        if (temp != 9)
            maxVal = replaceAndGetValue(num, size, temp, 9);
        else {
            if (lowMSD == Integer.MAX_VALUE)
                maxVal = num;
            else
                maxVal = replaceAndGetValue(num, size, lowMSD, 9);
        }

        if (temp != 1)
            minVal = replaceAndGetValue(num, size, temp, 1);
        else {
            if (highMSD == Integer.MIN_VALUE)
                minVal = num;
            else
                minVal = replaceAndGetValue(num, size, highMSD, 0);
        }

        return maxVal - minVal;
    }

    private final int replaceAndGetValue(int num, int size, int older, int newer) {
        int newVal = 0;
        for (int i = 0; i < size; i++) {
            int val = num / (int)Math.pow(10, size - i - 1);
            if (val == older) {
                newVal = newVal * 10 + newer;
            } else {
                newVal = newVal * 10 + val;
            }
            num = num % (int)Math.pow(10, size - i - 1);
        }

        return newVal;
    }
}