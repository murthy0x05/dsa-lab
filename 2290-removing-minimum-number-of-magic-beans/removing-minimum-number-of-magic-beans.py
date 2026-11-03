class Solution:
    def minimumRemoval(self, beans: list[int]) -> int:
        N = len(beans)

        beans.sort()

        total = sum(beans)
        result = float('inf')
        for i in range(N):
            result = min(result, total - (N - i) * beans[i])

        return result

