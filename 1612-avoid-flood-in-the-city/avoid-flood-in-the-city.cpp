class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        set<int> ids;
        unordered_map<int, int> seen;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                ids.insert(i);
            } else {
                if (seen.count(rains[i])) {
                    if (ids.empty()) {
                        return {};
                    }  
                    auto itr = ids.upper_bound(seen[rains[i]]);
                    if (itr == ids.end()) {
                        return {};
                    }
                    result[*itr] = rains[i];
                    ids.erase(itr);
                    seen.erase(rains[i]);
                }
                seen[rains[i]] = i; 
                result[i] = -1;
            }
        }

        for (const int& id: ids) {
            result[id] = 1;
        }

        return result;
    }
};