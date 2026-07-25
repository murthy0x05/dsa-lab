class ST {
    vector<int> tree;
    int N;
public:
    ST(vector<vector<int>>& arr) {
        N = arr.size();
        int L = 1 << ((32 - __builtin_clz(N) + ((N & (N - 1)) > 0)));
        tree.resize(L);
        build(arr, 0, 0, N - 1);
    }

    void build(vector<vector<int>>& arr, int node, int sl, int sr) {
        if (sl == sr) {
            tree[node] = arr[sl][3];
            return ;
        }

        int mid = sl + ((sr - sl) >> 1);
        build(arr, 2 * node + 1, sl, mid);
        build(arr, 2 * node + 2, mid + 1, sr);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
    int getMax(int node, int sl, int sr, int ql, int qr) {
        if (ql > sr or qr < sl) {
            return 0;
        }
        if (ql <= sl and qr >= sr) {
            return tree[node];
        }

        int mid = sl + ((sr - sl) >> 1);
        return max(getMax(2 * node + 1, sl, mid, ql, qr), getMax(2 * node + 2, mid + 1, sr, ql, qr));
    }
    int getMax(int ql, int qr) {
        if (ql <= qr) {
            return getMax(0, 0, N - 1, ql, qr);
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int N = s.size();

        vector<vector<int>> G;

        int cnt = 1;
        for (int i = 1; i < N; i++) {
            if (s[i - 1] == s[i]) {
                cnt++;
            } else {
                G.push_back({i - cnt, i - 1, s[i - 1] - '0', 0});
                cnt = 1;
            }
        }
        G.push_back({N - cnt, N - 1, s[N - 1] - '0', 0});


        for (int i = 1, L = G.size(); i < L - 1; i++) {
            if (G[i][2] == 1) {
                G[i][3] = max(0, (G[i - 1][1] - G[i - 1][0] + 1) + (G[i + 1][1] - G[i + 1][0] + 1));
            }
        }

        // for (const vector<int>& g: G) {
        //     cout << g[0] << ' ' << g[1] << ' ' << g[2] << ' ' << g[3] << endl;
        // }

        vector<int> opc(N + 1);
        for (int i = 0; i < N; i++) {
            opc[i + 1] = (s[i] - '0') + opc[i];
        }

        function<int(const int&)> bs = [&] (const int& id) {
            int l = 0, r = G.size() - 1;
            while (l <= r) {
                int m = l + ((r - l) >> 1);
                if (id >= G[m][0] and id <= G[m][1]) {
                    return m;
                } else if (id < G[m][0]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            return -1;
        };

        ST st(G);
        vector<int> result;
        for (const vector<int>& Q: queries) {
            int l = Q[0], r = Q[1];

            // int have = opc[r + 1] - opc[l];
            int have = opc[N];
            int sId = bs(l), eId = bs(r);
            // cout << sId << ' ' << eId << endl;
            if ((sId + 2) > eId) {
                result.push_back(have);
                continue;
            }

            if (G[sId][2] == 1 and G[eId][2] == 1) {
                result.push_back(have + st.getMax(sId + 1, eId - 1));
                // cout << ":11: " << st.getMax(sId + 1, eId - 1) << endl;
            } else if (G[sId][2] == 1 and G[eId][2] == 0) {
                result.push_back(have + max(
                                            st.getMax(sId + 1, eId - 2),
                                            (G[eId - 2][1] - G[eId - 2][0] + 1) +
                                            (r - G[eId][0] + 1)
                                        ));
            } else if (G[sId][2] == 0 and G[eId][2] == 1) {
                result.push_back(have + max(
                                            st.getMax(sId + 2, eId - 1),
                                            (G[sId + 2][1] - G[sId + 2][0] + 1) +
                                            (G[sId][1] - l + 1)
                                        ));
            } else {
                if ((sId + 2) == eId) {
                    result.push_back(have + ((r - l + 1) - (opc[r + 1] - opc[l])));
                    continue;
                }
                result.push_back(have + max({
                                            st.getMax(sId + 2, eId - 2),
                                            (G[sId + 2][1] - G[sId + 2][0] + 1) +
                                            (G[sId][1] - l + 1),
                                            (G[eId - 2][1] - G[eId - 2][0] + 1) +
                                            (r - G[eId][0] + 1)
                                        }));
            }
        }

        return result;
    }
};