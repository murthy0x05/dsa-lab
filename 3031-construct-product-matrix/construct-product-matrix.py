class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        prod = 1
        n , m = len(grid) , len(grid[0])
        mod = 12345

        ans = [[0 for _ in range(m)] for _ in range(n)]

        for i in range(n) :
            for j in range(m) :
                ans[i][j] = prod % mod
                prod %= mod
                prod *= grid[i][j]

        prod = 1
        for i in range(n-1 , -1 , -1) :
            for j in range(m-1 , -1 , -1) :
                ans[i][j] = (ans[i][j] * prod) % mod
                prod %= mod
                prod *= grid[i][j]
        
        return (ans)