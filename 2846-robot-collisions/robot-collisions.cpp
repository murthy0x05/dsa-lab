class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = positions.size();

        vector<int> ids(N);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&](const int& id1, const int& id2) {
            return positions[id1] < positions[id2];
        });

        vector<int> robots;
        vector<int> result;
        for (int i = 0; i < N; i++) {
            if (robots.empty()) {
                if (directions[ids[i]] == 'R') {
                    robots.push_back(ids[i]);
                }
            } else {
                if (directions[ids[i]] == 'L') {
                    while (!robots.empty() && healths[ids[i]] > healths[robots.back()]) {
                        healths[robots.back()] = 0;
                        robots.pop_back();
                        healths[ids[i]]--;
                    }
                    if (!robots.empty()) {
                        if (healths[robots.back()] == healths[ids[i]]) {
                            healths[ids[i]] = 0;
                            healths[robots.back()] = 0;
                            robots.pop_back();
                        } else if (healths[robots.back()] > healths[ids[i]]) {
                            healths[robots.back()]--;
                            healths[ids[i]] = 0;
                        }
                    }
                } else {
                    robots.push_back(ids[i]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (healths[i] != 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};