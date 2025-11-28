class Solution {
    int deleted = 0;
    int dfs(vector<vector<int>>& adjlist, vector<int>& nums, int parent, int curr, int sum) {

        int total = nums[curr];
        for (int& nbr: adjlist[curr]) {
            if (nbr != parent) {
                int val = dfs(adjlist, nums, curr, nbr, sum);
                if (val == sum) {
                    deleted++;
                } else {
                    total += val;
                    if (total > sum) {
                        deleted = -1;
                        return total;
                    }
                }
            }
        }
        
        return total;
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        cout << n << endl;
        vector<vector<int>> adjlist(n);
        for (vector<int>& edge: edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int maxval = *max_element(nums.begin(), nums.end());
        for (int i = total; i >= 2; i--) {
            if (total % i == 0) {
                deleted = 0;
                if (total / i == dfs(adjlist, nums, -1, 0, total / i)) {
                    if (deleted != -1) {
                        return deleted;
                    }
                }
            }
        }

        return 0;
    }
};