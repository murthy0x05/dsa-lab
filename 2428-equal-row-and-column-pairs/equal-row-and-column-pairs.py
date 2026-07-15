class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        table = defaultdict(int)
        for i in range(R):
            h = 0
            for j in range(C):
                h = h ^ grid[i][j]
                h = h << 11
                h = h * 5 + 0xea43cbe4
            table[h] += 1
        
        result = 0
        for j in range(C):
            h = 0
            for i in range(R):
                h = h ^ grid[i][j]
                h = h << 11
                h = h * 5 + 0xea43cbe4
            result += table[h]
        
        return result