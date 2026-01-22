class Solution {
    using ll = long long;
    struct state {
        ll sum;
        int id;
        state(ll s, int i) : sum(s), id(i) {}
    };
    struct ele {
        ll val;
        int id;
        ele(int v, int i) : val(v), id(i) {}
    };
public:
    inline int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        
        int invalid = 0;
        for (int i = 0; i < n - 1; i++)
            invalid += nums[i] > nums[i + 1];

        list<ele> dll;
        vector<list<ele>::iterator> its;
        for (int i = 0; i < n; i++) {
            dll.push_back(ele(nums[i], i));
            its.push_back(--dll.end());
        }

        auto cmp = [&](state& x, state& y) {
            if (x.sum != y.sum) {
                return x.sum > y.sum;
            } else {
                return x.id > y.id;
            }
        };
        priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n - 1; i++)
            pq.push(state(0LL + nums[i] + nums[i + 1], i));

        int result = 0;
        while (invalid > 0) {
            state curr = pq.top(); pq.pop();

            if (its[curr.id] == (list<ele>::iterator)nullptr) continue;
            list<ele>::iterator a1 = its[curr.id];
            list<ele>::iterator a2 = next(a1);
            if (a2 == dll.end()) continue;

            list<ele>::iterator a3 = next(a2),
                                a0 = prev(a1); // sos

            if (curr.sum == (0LL + a1 -> val + a2 -> val)) {
                invalid -= (a1 -> val > a2 -> val);

                if (a1 != dll.begin()) {
                    invalid -= (a0 -> val > a1 -> val);
                }
                if (a3 != dll.end()) {
                    invalid -= (a2 -> val > a3 -> val);
                }

                its[a2 -> id] = (list<ele>::iterator)nullptr;
                a1 -> val += a2 -> val;
                dll.erase(a2);

                if (a1 != dll.begin()) {
                    pq.push(state(0LL + a0 -> val + a1 -> val, a0 -> id));
                    invalid += (a0 -> val > a1 -> val);
                }
                if (a3 != dll.end()) {
                    pq.push(state(a1 -> val + a3 -> val, a1 -> id));
                    invalid += (a1 -> val > a3 -> val);
                }

                result++;
            }
        }

        return result;


    }
};