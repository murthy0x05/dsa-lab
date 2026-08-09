class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int N = stoneValue.size();

        vector<int> ps(N + 1);
        for (int i = 0; i < N; i++) {
            ps[i + 1] = stoneValue[i] + ps[i];
        }

        int result = 0;
        int mem[501][501];
        memset(mem, -1, sizeof(mem));
        auto f = [&] (auto&& f, int l, int r) -> int {
            
            if (mem[l][r] != -1) {
                return mem[l][r];
            }

            int largest = 0;
            for (int mid = l; mid < r; mid++) {
                int LS = ps[mid + 1] - ps[l];
                int RS = ps[r + 1] - ps[mid + 1];

                // cout << l << ' ' << mid << ' ' << r << ' ' << LS << ' ' << RS << endl;

                if (LS == RS) {
                    largest = max({largest, LS + f(f, l, mid), RS + f(f, mid + 1, r)});
                } else if (LS < RS) {
                    largest = max(largest, LS + f(f, l, mid));
                } else {
                    largest = max(largest, RS + f(f, mid + 1, r));
                }
            }

            return mem[l][r] = largest;
        };

        return f(f, 0, N - 1);
    }
};