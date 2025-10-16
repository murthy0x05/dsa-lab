class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        n = len(nums)

        counts = [0] * (value + 1)
        for num in nums:
            counts[((num % value) + value) % value] += 1
        
        for i in range(n):
            if (counts[i % value] > 0):
                counts[i % value] -= 1
            else:
                return i

        return n