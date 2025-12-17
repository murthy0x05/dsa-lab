// class Solution {
//     using ll = long long;
//     int n;
//     vector<vector<vector<ll>>> mem;
//     ll dfs(vector<int>& prices, int curr, int k, bool buy, bool sell) {
//         if (k == 0) {
//             return 0;
//         }
//         if (mem[curr][buy][sell] != -1) {
//             return mem[curr][buy][sell];
//         }
//         if (curr + 1 == n) {
//             if (!buy && !sell) {
//                 return mem[curr][buy][sell] = -1e12;
//             } else if (buy && !sell) {
//                 return mem[curr][buy][sell] = prices[curr]; 
//             } else {
//                 return mem[curr][buy][sell] = -prices[curr];
//             }
//         }

//         if (!buy && !sell) {
//             // SKIP
//             ll maxv = -1e12;

//             maxv = max(maxv, prices[curr] + dfs(prices, curr + 1, k, false, true));
//             maxv = max(maxv, -prices[curr] + dfs(prices, curr + 1, k, true, false));
//             maxv = max(maxv, dfs(prices, curr + 1, k, buy, sell));

//             return mem[curr][buy][sell] = maxv;
//         } else if (!buy && sell) {
//             ll maxv = -1e12;

//             maxv = max(maxv, -prices[curr] + dfs(prices, curr + 1, k, false, false));
//             maxv = max(maxv, dfs(prices, curr + 1, k, buy, sell));

//             return mem[curr][buy][sell] = maxv;
//         } else { // buy && !sell
//             ll maxv = -1e12;

//             maxv = max(maxv, prices[curr] + dfs(prices, curr + 1, k, false, false));
//             maxv = max(maxv, dfs(prices, curr + 1, k, buy, sell));

//             return mem[curr][buy][sell] = maxv;
//         }
//     }
// public:
//     long long maximumProfit(vector<int>& prices, int k) {
//         this -> n = prices.size();
        
//         mem.reserve(n);
//         mem.assign(n, vector<vector<ll>>(2, vector<ll>(2, -1)));

//         return dfs(prices, 0, k, 0, 0);
//     }
// };

class Solution 
{
public:
    long long helper(int ind, int n, vector<int>& prices, int k, int canBuy, int type,
                     vector<vector<vector<vector<long long>>>> &dp)
    {
        if(ind == n || k == 0)
        {
            if(canBuy == 1) return 0;
            return -1e9;
        }

        int t = type + 1;

        if(dp[ind][k][canBuy][t] != LLONG_MIN) return dp[ind][k][canBuy][t];

        long long res;

        if(canBuy == 1)
        {
            long long buy    = -1LL * prices[ind] + helper(ind+1, n, prices, k, 0, 0, dp);
            long long shtBuy =  1LL * prices[ind] + helper(ind+1, n, prices, k, 0, 1, dp);
            long long skip   = helper(ind+1, n, prices, k, 1, -1, dp);

            res = max({buy, shtBuy, skip});
        }
        else
        {
            long long sell = 0;

            if(type == 0)  
                sell =  1LL * prices[ind] + helper(ind+1, n, prices, k-1, 1, -1, dp);
            else if(type == 1)
                sell = -1LL * prices[ind] + helper(ind+1, n, prices, k-1, 1, -1, dp);

            long long skip = helper(ind+1, n, prices, k, 0, type, dp);

            res = max(sell, skip);
        }

        return dp[ind][k][canBuy][t] = res;
    }

    long long maximumProfit(vector<int>& prices, int k) 
    {
        int n = prices.size();

        vector<vector<vector<vector<long long>>>> dp(
            n, vector<vector<vector<long long>>>(
                k+1, vector<vector<long long>>(
                    2, vector<long long>(3, LLONG_MIN)
                )
            )
        );

        return helper(0, n, prices, k, 1, -1, dp);
    }
};