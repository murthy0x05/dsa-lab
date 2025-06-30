class MaximumQueue {
    queue<int> q; deque<int> d;
public:
    inline void enqueue(int num) {
        if (q.size() == 0) {
            q.push(num);
            d.push_back(num);
        } else {
            q.push(num);
            while (!d.empty() && d.back() < num) {
                d.pop_back();
            }
            d.push_back(num);
        }
    }
    inline void dequeue() {
        if (q.front() == d.front()) {
            q.pop(); d.pop_front();
        } else {
            q.pop();
        }
    }
    inline int getMax() {
        return d.front();
    }
};

class Solution {
public:
    inline vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        MaximumQueue maxQueue;
        for (int i = 0; i < k - 1; i++) {
            maxQueue.enqueue(nums[i]);
        }
        vector<int> result(n - k + 1);
        for (int i = k - 1; i < n; i++) {
            maxQueue.enqueue(nums[i]);
            result[i - k + 1] = maxQueue.getMax();
            maxQueue.dequeue();
        }

        return result;

    }
};