class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        function<bool(int)> feasible = [&](int size) {
            vector<int> counts(26, 0);
            for (int l = 0, r = 0; r < n; r++) {
                counts[s[r] - 'A']++;
                if (r - l + 1 == size) {
                    int max_occ = *max_element(counts.begin(), counts.end());
                    if (size == 4) {
                        cout << "MO: " << max_occ << endl;
                    }
                    if (size - max_occ <= k) {
                        return true;
                    }
                    counts[s[l] - 'A']--;
                    l++;
                }
            }

            return false;
        };

        int low = 1, high = n;
        int len = 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(mid)) {
                len = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return len;
    }
};