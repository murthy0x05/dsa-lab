class Solution {
    using ll = long long;
public:
    long long maxSumTrionic(vector<int>& nums) {
        const int n = nums.size();
        const ll INF = 1e14 + 1;

        int l = -1, p = -1, q = -1, r = -1;
        ll lp = 0, pq = 0, qr = 0;
        ll lp_rem = 0, qr_rem = 0;
        ll result = -INF;
        for (int i = 1; i < n; i++) {
            if (l == -1) {
                lp = pq = qr = 0;
                l = i - 1;
                lp = nums[l];
                lp_rem = 0;
                p = i;

                while (p < n && nums[p - 1] < nums[p]) {
                    lp += nums[p];
                    p++;
                }
                if ((p - l) < 2 || p >= n) {
                    // cout << l << " -> " << p << endl;
                    l = -1;
                    i = p;
                    continue;
                }

                p--;
                lp -= nums[p];
                pq = nums[p];
                q = p + 1;
                while (q < n && nums[q - 1] > nums[q]) {
                    pq += nums[q];
                    q++;
                }
                if ((q - p) < 2 || q >= n) {
                    l = -1;
                    i = q;
                    continue;
                }

                q--;
                pq -= nums[q];
                qr = nums[q];
                qr_rem = 0;
                r = q + 1;
                while (r < n && nums[r - 1] < nums[r]) {
                    qr += nums[r];
                    r++;
                }
                if ((r - q) < 2) {
                    l = -1;
                    i = r;
                    continue;
                }

                ll lp_neg = 0;
                ll curr_neg = 0;
                for (int x = l; x < p - 1; x++) {
                    curr_neg += nums[x];
                    lp_neg = min(lp_neg, curr_neg);
                }

                ll qr_neg = 0;
                curr_neg = 0;
                for (int x = r - 1; x > q + 1; x--) {
                    curr_neg += nums[x];
                    qr_neg = min(qr_neg, curr_neg);
                }


                result = max(result, (lp - lp_neg) + pq + (qr - qr_neg));
                // cout << l << " -> " << p << " = " << lp << " - " << lp_neg << endl;
                // cout << p << " -> " << q << " = " << pq << endl;
                // cout << q << " -> " << r << " = " << qr << " - " << qr_neg << endl;
                // cout << lp + pq + qr << endl;
                
                l = q; p = r;
                lp = qr;
                i = r;
            } else {
                p--;
                lp -= nums[p];
                pq = nums[p];
                q = p + 1;
                while (q < n && nums[q - 1] > nums[q]) {
                    pq += nums[q];
                    q++;
                }
                if ((q - p) < 2 || q >= n) {
                    l = -1;
                    i = q;
                    continue;
                }

                q--;
                pq -= nums[q];
                qr = nums[q];
                r = q + 1;
                while (r < n && nums[r - 1] < nums[r]) {
                    qr += nums[r];
                    r++;
                }
                if ((r - q) < 2) {
                    l = -1;
                    i = r;
                    continue;
                }

                ll lp_neg = 0;
                ll curr_neg = 0;
                for (int x = l; x < p - 1; x++) {
                    curr_neg += nums[x];
                    lp_neg = min(lp_neg, curr_neg);
                }

                ll qr_neg = 0;
                curr_neg = 0;
                for (int x = r - 1; x > q + 1; x--) {
                    curr_neg += nums[x];
                    qr_neg = min(qr_neg, curr_neg);
                }

                result = max(result, (lp - lp_neg) + pq + (qr - qr_neg));
                // cout << l << " -> " << p << " = " << lp << " - " << lp_neg << endl;
                // cout << p << " -> " << q << " = " << pq << endl;
                // cout << q << " -> " << r << " = " << qr << " - " << qr_neg << endl;
                // cout << lp + pq + qr << endl;
                // cout << l << " -> " << p << " = " << lp << endl;
                // cout << l << ' ' << r << endl;

                l = q; p = r;
                lp = qr;
                i = r;
            }
        }

        return result;
    }
};