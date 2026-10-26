class Solution:
    def countTriplets(self, arr: list[int]) -> int:
        N = len(arr)
        if N == 1:
            return 0

        px = [0 for _ in range(N + 1)]
        for i in range(N):
            px[i + 1] = px[i] ^ arr[i]

        result = 0
        for i in range(N):
            for j in range(i + 1, N):
                for k in range(j, N):
                    if px[j] ^ px[i] == px[k + 1] ^ px[j]:
                        result += 1

        return result