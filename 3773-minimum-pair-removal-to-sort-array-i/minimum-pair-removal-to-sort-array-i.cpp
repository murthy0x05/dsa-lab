class Solution {
    struct state {
        int sum, id;
        state(int s, int i) : sum(s), id(i) {}
    };
    struct ele {
        int val, id;
        ele(int v, int i) : val(v), id(i) {}
    };
public:
    int minimumPairRemoval(vector<int>& nums) {
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
            pq.push(state(nums[i] + nums[i + 1], i));

        cout << "Value of Invalid: " << invalid << endl;

        int result = 0;
        while (invalid > 0) {
            state curr = pq.top(); pq.pop();

            if (its[curr.id] == (list<ele>::iterator)nullptr) continue;
            list<ele>::iterator a1 = its[curr.id];
            list<ele>::iterator a2 = next(a1),
                                a3 = next(a2), // sos
                                a0 = prev(a1); // sos
            if (a2 == dll.end()) continue;

            if (curr.sum == (a1 -> val + a2 -> val)) {
                invalid -= (a1 -> val > a2 -> val);

                if (a1 != dll.begin()) {
                    invalid -= (a0 -> val > a1 -> val);
                }
                if (a3 != dll.end()) {
                    invalid -= (a2 -> val > a3 -> val);
                }

                its[a2 -> id] = (list<ele>::iterator)nullptr;

                cout << "curr idx: " << a1 -> id << ", and value is: " << a1 -> val << endl;
                cout << "a2 idx: " << a2 -> id << ", and value is: " << a2 -> val << endl;
                a1 -> val += a2 -> val;

                dll.erase(a2);

                for (auto [val, id]: dll) cout << val << ' ';
                cout << endl;

                if (a1 != dll.begin()) {
                    pq.push(state(a0 -> val + a1 -> val, a0 -> id));
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