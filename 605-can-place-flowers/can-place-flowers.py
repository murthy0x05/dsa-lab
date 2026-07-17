class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        fb = [0] + flowerbed + [0]

        N = len(fb)
        placed = 0
        C = 1
        while C < N - 1:
            if fb[C - 1] == fb[C] == fb[C + 1] == 0:
                placed += 1
                C += 1
            C += 1
        
        return placed >= n