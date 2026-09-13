class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        N = len(img1)

        A = [(i, j) for i in range(N) for j in range(N) if img1[i][j] == 1]
        B = [(i, j) for i in range(N) for j in range(N) if img2[i][j] == 1]

        best = 0
        cnt = [[0] * (2 * N) for _ in range(2 * N)]

        for ax, ay in A:
            for bx, by in B:
                dx = bx - ax + N
                dy = by - ay + N
                cnt[dx][dy] += 1
                best = max(best, cnt[dx][dy])
        
        return best