// class Solution {
//     using ll = long long;
// public:
//     long long minOperations(vector<vector<int>>& queries) {
//         vector<ll> p(16, 1);
//         for (int i = 1; i < 16; i++) {
//             p[i] = p[i - 1] * 4;
//         }
        
//         ll ops = 0;
//         for (vector<int>& query: queries) {
//             int l = query[0], r = query[1];

//             int low = 0, high = 0;
//             while (p[low] < l) low++;

//             int low = ceil(log2(l) / 2.0);
//             int high = floor(log2(r) / 2.0);
//             if (l >= p[floor(log2(l))] && r < p[ceil(log2(r))]) {
//                 ops += (r - l + 1) * (ll)ceil((floor(log2(l)) + 1) / 2.0);
//             } else {
//                 ll d = (min<ll>((ll)r + 1, p[low]) - l) * (ll)ceil((floor(log2(l)) + 1) / 2.0);
//                 d += (r - max<ll>((ll)l, p[high]) + 1) * (ll)ceil((floor(log2(r)) + 1) / 2.0);
//                 for (int i = low; i < high; i++) {
//                     d += (p[i + 1] - p[i]) * (ll)ceil((i + 1) / 2.0);
//                 }

//                 ops += (ll)ceil(d / 2.0);

//             }
//         }

//         return ops;
//     }
// };

class Solution {
public:

    long long solve(vector<vector<long long>> &vt, long long left, long long right) {
        long long ops = 0;
        int level = vt.size();

        int i = left;
        while(i<=right) {
            for(int j = 0;j<level;j++) {
                if(vt[j][0] <= i && i < vt[j][1]) {
                    long long total_num = (min(right, vt[j][1]-1) - i + 1);
                    ops += (vt[j][2] * total_num);
                    i = vt[j][1];
                    break;
                }
            }
        }
        return (ops+1)/2;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        int n = queries.size();
        vector<vector<long long>> vt;
        for(long long i = 1,op = 1;i<1e16;i*=4,op++) {
            vt.push_back({i, i*4, op});
        }

        for(int i = 0;i<n;i++) {
            ans += solve(vt, queries[i][0], queries[i][1]);
        }
        return ans;
    }
};

