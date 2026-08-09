class Solution {
    bool f1 (vector<int> mods, int N) {
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (i & 1) {
                if ((total + 0) % 3 != 0 and mods[0] > 0) {
                    mods[0] -= 1;
                } else if ((total + 1) % 3 != 0 and mods[1] > 0) {
                    mods[1] -= 1;
                    total = (total + 1) % 3;
                } else if ((total + 2) % 3 != 0 and mods[2] > 0) {
                    mods[2] -= 1;
                    total = (total + 2) % 3;
                } else {
                    return true;
                }
            } else {
                if ((total + 0) % 3 != 0 and mods[0] > 0) {
                    mods[0] -= 1;
                } else if ((total + 1) % 3 != 0 and mods[1] > 0) {
                    mods[1] -= 1;
                    total = (total + 1) % 3;
                } else if ((total + 2) % 3 != 0 and mods[2] > 0) {
                    mods[2] -= 1;
                    total = (total + 2) % 3;
                } else {
                    return false;
                }
            }

        }

        return false;
    }
    bool f2 (vector<int> mods, int N) {
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (i & 1) {
                if ((total + 0) % 3 != 0 and mods[0] > 0) {
                    mods[0] -= 1;
                } else if ((total + 2) % 3 != 0 and mods[2] > 0) {
                    mods[2] -= 1;
                    total = (total + 2) % 3;
                } else if ((total + 1) % 3 != 0 and mods[1] > 0) {
                    mods[1] -= 1;
                    total = (total + 1) % 3;
                } else {
                    return true;
                }
            } else {
                if ((total + 0) % 3 != 0 and mods[0] > 0) {
                    mods[0] -= 1;
                } else if ((total + 2) % 3 != 0 and mods[2] > 0) {
                    mods[2] -= 1;
                    total = (total + 2) % 3;
                } else if ((total + 1) % 3 != 0 and mods[1] > 0) {
                    mods[1] -= 1;
                    total = (total + 1) % 3;
                } else {
                    return false;
                }
            }

        }

        return false;
    }
public:
    bool stoneGameIX(vector<int>& stones) {
        const int N = stones.size();

        vector<int> mods(3, 0);
        for (int i = 0; i < N; i++) {
            mods[stones[i] % 3]++;
        }

        return f1(mods, N) or f2(mods, N);
    }
};