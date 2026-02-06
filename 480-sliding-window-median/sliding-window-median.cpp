class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<double> result; result.reserve(N);
        multiset<int> left, right;

        for (int i = 0; i < N; i++) {
            if (i < (k - 1)) {
                if (left.empty()) {
                    left.insert(nums[i]);
                } else {
                    if (*prev(left.end()) >= nums[i]) {
                        left.insert(nums[i]);
                    } else {
                        right.insert(nums[i]);
                    }

                    if (abs<int>(left.size() - right.size()) > 1) {
                        if (left.size() > right.size()) {
                            right.insert(*prev(left.end()));
                            left.erase(prev(left.end()));
                        } else {
                            left.insert(*right.begin());
                            right.erase(right.begin());
                        }
                    }
                }
            } else {
                if (left.empty()) {
                    left.insert(nums[i]);
                } else {
                    if (*prev(left.end()) >= nums[i]) {
                        left.insert(nums[i]);
                    } else {
                        right.insert(nums[i]);
                    } 
                }


                if (abs<int>(left.size() - right.size()) > 1) {
                    if (left.size() > right.size()) {
                        right.insert(*prev(left.end()));
                        left.erase(prev(left.end()));
                    } else {
                        left.insert(*right.begin());
                        right.erase(right.begin());
                    }
                }

                if (left.size() == right.size()) {
                    result.push_back((0LL + *prev(left.end()) + *right.begin()) / 2.0);
                } else if (left.size() > right.size()) {
                    result.push_back(*prev(left.end()));
                } else {
                    result.push_back(*right.begin());
                }

                if (left.find(nums[i - k + 1]) != left.end()) {
                    left.erase(left.find(nums[i - k + 1]));
                } else {
                    right.erase(right.find(nums[i - k + 1]));
                }
                
                if (abs<int>(left.size() - right.size()) > 1) {
                    if (left.size() > right.size()) {
                        right.insert(*prev(left.end()));
                        left.erase(prev(left.end()));
                    } else {
                        left.insert(*right.begin());
                        right.erase(right.begin());
                    }
                }









            }
        }

        return result;
    }
};