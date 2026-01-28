class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        const int r = grid.size(),
                  c = grid[0].size(),
                  INF = (r + c - 2) * 10000 + 1;

        vector<vector<int>> prev(r, vector<int>(c, INF)),
                            curr(r, vector<int>(c, INF));
        
        prev[0][0] = 0;
        for (int i = 1; i < r; i++) 
            prev[i][0] = grid[i][0] + prev[i - 1][0];
        for (int j = 1; j < c; j++) 
            prev[0][j] = grid[0][j] + prev[0][j - 1];
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                prev[i][j] = grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]);
            }
        }
        
        vector<int> ids(r * c);
        iota(ids.begin(), ids.end(), 0);
        // sort(ids.begin(), ids.end(), [&](const int& a, const int& b) {
        //     int ra = a / c, ca = a % c;
        //     int rb = b / c, cb = b % c;
        //     if (grid[ra][ca] != grid[rb][cb]) {
        //         return grid[ra][ca] > grid[rb][cb];
        //     } else {
        //         return prev[ra][ca] < prev[rb][cb];
        //     }
        // });

        for (int k = 1; k <= K; k++) {
            sort(ids.begin(), ids.end(), [&](const int& a, const int& b) {
                int ra = a / c, ca = a % c;
                int rb = b / c, cb = b % c;
                if (grid[ra][ca] != grid[rb][cb]) {
                    return grid[ra][ca] > grid[rb][cb];
                } else {
                    return prev[ra][ca] < prev[rb][cb];
                }
            });

            int Min = INF;
            for (const int& id: ids) {
                int i = id / c, j = id % c;
                Min = min(Min, prev[i][j]);
                curr[i][j] = Min;
            }
            prev = curr;

            for (int i = 1; i < r; i++) 
                prev[i][0] = min(prev[i][0], grid[i][0] + prev[i - 1][0]);
            for (int j = 1; j < c; j++) 
                prev[0][j] = min(prev[0][j], grid[0][j] + prev[0][j - 1]);
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    prev[i][j] = min(prev[i][j], grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]));
                }
            }
        }

        return prev.back().back();
    }
};

// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid, int K) {
//         const int r = grid.size();
//         const int c = grid[0].size();
//         const int INF = (r + c - 2) * 10000 + 5;

//         vector<vector<int>> prev(r, vector<int>(c, INF));
//         vector<vector<int>> curr(r, vector<int>(c, INF));

//         // Base DP: 0 teleports
//         prev[0][0] = 0;
//         for (int i = 1; i < r; i++)
//             prev[i][0] = prev[i - 1][0] + grid[i][0];
//         for (int j = 1; j < c; j++)
//             prev[0][j] = prev[0][j - 1] + grid[0][j];
//         for (int i = 1; i < r; i++) {
//             for (int j = 1; j < c; j++) {
//                 prev[i][j] = grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]);
//             }
//         }

//         // Sort cells by grid value ASCENDING
//         vector<int> ids(r * c);
//         iota(ids.begin(), ids.end(), 0);
//         sort(ids.begin(), ids.end(), [&](int a, int b) {
//             int ra = a / c, ca = a % c;
//             int rb = b / c, cb = b % c;
//             return grid[ra][ca] > grid[rb][cb];
//         });

//         // Teleport layers
//         for (int k = 1; k <= K; k++) {

//             // Reset curr
//             // for (int i = 0; i < r; i++)
//             //     for (int j = 0; j < c; j++)
//             //         curr[i][j] = INF;

//             // // Prefix minimum over sorted cells
//             // vector<int> prefixMin(ids.size());
//             // for (int t = 0; t < ids.size(); t++) {
//             //     int i = ids[t] / c;
//             //     int j = ids[t] % c;
//             //     prefixMin[t] = prev[i][j];
//             //     if (t > 0) prefixMin[t] = min(prefixMin[t], prefixMin[t - 1]);
//             // }

//             // // Teleport assignment
//             // for (int t = 0; t < ids.size(); t++) {
//             //     int i = ids[t] / c;
//             //     int j = ids[t] % c;
//             //     curr[i][j] = prefixMin[t];
//             // }

//             // prev = curr;

//             int Min = INF;
//             for (const int& id: ids) {
//                 int i = id / c, j = id % c;
//                 Min = min(Min, prev[i][j]);
//                 curr[i][j] = Min;
//             }
//             prev = curr;

//             // Normal DP relaxation
//             for (int i = 1; i < r; i++)
//                 prev[i][0] = min(prev[i][0], prev[i - 1][0] + grid[i][0]);
//             for (int j = 1; j < c; j++)
//                 prev[0][j] = min(prev[0][j], prev[0][j - 1] + grid[0][j]);
//             for (int i = 1; i < r; i++) {
//                 for (int j = 1; j < c; j++) {
//                     prev[i][j] = min(prev[i][j],
//                         grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]));
//                 }
//             }
//         }

//         return prev[r - 1][c - 1];
//     }
// };
