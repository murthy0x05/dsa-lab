class Solution:
    def longestMountain(self, arr: list[int]) -> int:
        N = len(arr)

        P, S = [0 for _ in range(N)], [0 for _ in range(N)]
        
        P[0] = 1
        for i in range(1, N):
            if arr[i - 1] < arr[i]:
                P[i] += 1 + P[i - 1]
            else:
                P[i] = 1

        S[N - 1] = 1
        for i in range(N - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                S[i] += 1 + S[i + 1]
            else:
                S[i] = 1
        
        longest = 0
        for i in range(1, N - 1):
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                longest = max(longest, P[i] + S[i] - 1)
        
        return longest