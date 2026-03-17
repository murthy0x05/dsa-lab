class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        M, N = len(matrix), len(matrix[0])

        prev = [0] * N
        largest = 0
        for i in range(M):
            curr = matrix[i][::]
            for j in range(N):
                if curr[j] > 0:
                    curr[j] += prev[j]
            
            sortedCurr = sorted(curr, reverse = True)
            for j in range(N):
                largest = max(largest, (j + 1) * sortedCurr[j])
            prev = curr
        
        return largest
