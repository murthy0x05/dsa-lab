// class Solution {
//     List<List<Integer>> mem;
//     private int solve(int[] arr, int i, int j) {
//         if (i == j) {
//             mem.get(i).set(j, 0);
//             return 0;
//         }
//         if (mem.get(i).get(j) != -1) {
//             return mem.get(i).get(j);
//         }

//         int maxi = Integer.MIN_VALUE;
//         for (int k = i; k <= j - 1; k++) {
//             int cost = arr[i - 1] * arr[k] * arr[j] +
//                        solve(arr, i, k) +
//                        solve(arr, k + 1, j);
//             maxi = Math.max(maxi, cost);
//         } 

//         mem.get(i).set(j, maxi);
//         return maxi;
//     }
//     public int maxCoins(int[] nums) {
//         int n = nums.length;
//         mem = new ArrayList<>();
//         for (int i = 0; i < n + 2; i++) {
//             mem.add(new ArrayList<>());    
//             for (int j = 0; j < n + 2; j++) {
//                 mem.get(i).add(Integer.valueOf(-1));
//             }
//         }

//         int[] arr = new int[n + 2];
//         arr[0] = 1;
//         arr[n + 1] = 1;
//         for (int i = 1; i <= n; i++) {
//             arr[i] = nums[i - 1];
//         }

//         return solve(arr, 1, n + 1);
//     }
// }

class Solution {
    int[][] mem;
    private int solve(int[] arr, int i, int j) {
        if (i == j) {
            return mem[i][j] = 0;
        }
        if (mem[i][j] != -1) {
            return mem[i][j];
        }

        int maxCoins = Integer.MIN_VALUE;
        for (int k = i; k <= j - 1; k++) {
            int coins = arr[i - 1] * arr[k] * arr[j] +
                       solve(arr, i, k) +
                       solve(arr, k + 1, j);
            maxCoins = Math.max(maxCoins, coins);
        }

        return mem[i][j] = maxCoins;
    }
    public int maxCoins(int[] nums) {
        int n = nums.length;
        mem = new int[n + 2][n + 2];
        for (int i = 0; i < n + 2; i++) {
            Arrays.fill(mem[i], -1);
        }

        int[] arr = new int[n + 2];
        arr[0] = 1; arr[n + 1] = 1;
        System.arraycopy(nums, 0, arr, 1, n);

        return solve(arr, 1, n + 1);
    }
}