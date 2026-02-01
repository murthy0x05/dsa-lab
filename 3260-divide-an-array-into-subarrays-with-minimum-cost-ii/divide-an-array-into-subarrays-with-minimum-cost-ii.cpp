class Solution {
    using ll = long long;
    using pii = pair<int, int>;
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int n = nums.size();

        ll cost = 1e14 + 1;
        ll currCost = 0LL;
        multiset<int> included, excluded;

        for (int i = 1; i < n; i++) {
            if (included.size() < (k - 1)) {
                included.insert(nums[i]);
                currCost += nums[i];
                if (included.size() < k - 1)
                    continue;
            } else {
                auto it1 = prev(included.end());
                if (*it1 > nums[i]) {
                    currCost += (nums[i] - (*it1));
                    excluded.insert(*it1);
                    included.erase(it1);
                    included.insert(nums[i]);
                } else {
                    excluded.insert(nums[i]);
                }
            }

            cost = min(cost, currCost);

            if (i - dist < 1) {
                continue;
            }

            if (excluded.size() == 0) {
                currCost -= nums[i - dist];
                included.erase(included.find(nums[i - dist]));
            } else {
                auto it2 = excluded.find(nums[i - dist]);
                if (it2 == excluded.end()) {
                    currCost += ((*excluded.begin()) - nums[i - dist]);
                    included.erase(included.find(nums[i - dist]));
                    included.insert(*excluded.begin());
                    excluded.erase(excluded.begin());
                } else {
                    excluded.erase(it2);
                }
            }













            // if (included.size() == (k - 1)) {
            //     auto it1 = prev(included.end());
            //     if (*it1 > nums[i]) {
            //         excluded.insert(*it1);
            //         currCost += nums[i] - (*it1);
            //         included.erase(it1);
            //         included.insert(nums[i]);
            //     } else {
            //         excluded.insert(nums[i]);
            //     }
            // } else {
            //     included.insert(nums[i]);
            //     currCost += nums[i];
            // }

            // if (included.size() == (k - 1))
            //     cost = min(cost, currCost);

            // if ((k - 1) < dist + 1 &&  i - dist >= 1) {
            //     auto it2 = excluded.find(nums[i - dist]);
            //     if (it2 == excluded.end()) {
            //         auto it3 = included.find(nums[i - dist]);
            //         currCost += (*excluded.begin()) - (*it3);
            //         included.erase(it3);
            //         included.insert(*excluded.begin());
            //         excluded.erase(excluded.begin());
            //     } else {
            //         excluded.erase(it2);
            //     }
            // }
        }

        return nums[0] + cost;
    }
};