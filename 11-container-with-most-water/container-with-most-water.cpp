class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int front = 0, rear = n - 1;
        int result = INT_MIN;

        while (front < rear) {
            if (height[front] < height[rear]) {
                result = max(result, (rear - front) * height[front]);
                front++;
            } else {
                result = max(result, (rear - front) * height[rear]);
                rear--;
            }
        }

        return result;
    }
};