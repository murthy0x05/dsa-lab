class Solution {
    public final int maxArea(int[] height) {
        int n = height.length;
        int result = Integer.MIN_VALUE;
        int front = 0, rear = n-1;

        while (front < rear) {
            int currHeight = Math.min(height[front], height[rear]);
            int currWidth = rear - front;
            int currArea = currHeight * currWidth;
            result = Math.max(result, currArea);

            if (height[front] < height[rear]) {
                while (front < rear && height[front] <= currHeight) {
                    front += 1;
                }
            } else {
                while (front < rear && height[rear] <= currHeight) {
                    rear -= 1;
                }
            }
        }

        return result;
    }
}