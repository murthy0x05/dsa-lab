class Solution {
    using ll = long long;
    typedef pair<int, int> pii;
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        function<bool(const pii&, const pii&)> cmp1 = [](const pii& a, const pii& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        };
        function<bool(const pii, const pii&)> cmp2 = [](const pii& a, const pii& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        };
        set<pii, decltype(cmp1)> topX(cmp1);
        set<pii, decltype(cmp2)> left(cmp2);

        int n = nums.size();
        unordered_map<int, int> counts;
        for (int i = 0; i < k; i++) {
            counts[nums[i]]++;
        }

        ll xsum = 0;
        for (const pii& p: counts) {
            if (topX.size() < x) {
                topX.insert(p);
                xsum += p.first * 1LL * p.second;
            } else {
                auto it = topX.begin();
                if (it -> second < p.second) {
                    left.insert(make_pair(it -> first, it -> second));
                    xsum += (p.first * 1LL * p.second) - (it -> first * 1LL * it -> second);
                    topX.erase(it);
                    topX.insert(p);
                } else if (it -> second > p.second) {
                    left.insert(p);
                } else {
                    if (it -> first < p.first) {
                        left.insert(make_pair(it -> first, it -> second));
                        xsum += (p.first * 1LL * p.second) - (it -> first * 1LL * it -> second);
                        topX.erase(it);
                        topX.insert(p);
                    } else {
                        left.insert(p);
                    }
                }
            }
        }

        vector<ll> result; result.push_back(xsum);
        for (int i = k; i < n; i++) {
            pii toErase1 = make_pair(nums[i - k], counts[nums[i - k]]);
            pii toErase2 = make_pair(nums[i], counts[nums[i]]);
            counts[nums[i - k]]--;
            counts[nums[i]]++;
            pii toInsert1 = make_pair(nums[i - k], counts[nums[i - k]]);
            pii toInsert2 = make_pair(nums[i], counts[nums[i]]);
            if (topX.erase(toErase1)) {
                xsum -= (toErase1.first * 1LL * toErase1.second);
            } else {
                left.erase(toErase1);
            }
            if (topX.erase(toErase2)) {
                xsum -= (toErase2.first * 1LL * toErase2.second);
            } else {
                left.erase(toErase2);
            }

            left.insert(toInsert1);
            left.insert(toInsert2);
            while (!left.empty() && topX.size() < x) {
                xsum += (left.begin() -> first * 1LL * left.begin() -> second);
                topX.insert(*left.begin());
                left.erase(left.begin());
            }
            while (!left.empty() && ((topX.begin() -> second < left.begin() -> second) ||
                  ((topX.begin() -> second == left.begin() -> second) &&
                  (topX.begin() -> first < left.begin() -> first)))) {
                xsum -= (topX.begin() -> first * 1LL * topX.begin() -> second);
                xsum += (left.begin() -> first * 1LL * left.begin() -> second);
                pii p = *left.begin();
                left.erase(left.begin());
                left.insert(*topX.begin());
                topX.erase(topX.begin());
                topX.insert(p);
            }

            result.push_back(xsum);
        }

        return result;
    }
};