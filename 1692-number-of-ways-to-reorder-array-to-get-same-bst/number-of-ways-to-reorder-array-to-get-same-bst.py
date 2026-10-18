
class Solution:
    MOD = 10 ** 9 + 7

    def numOfWays(self, nums: list[int]) -> int:
        n = len(nums)
        born = [-1] * (n + 2)

        for i, num in enumerate(nums):
            born[num] = i

        fact = 1
        for k in range(2, n + 1):
            fact = fact * k % self.MOD

        sizes = 1
        stack = [0]

        for v in range(1, n + 2):
            while born[stack[-1]] > born[v]:
                stack.pop()
                sizes = sizes * (v - stack[-1] - 1) % self.MOD
            stack.append(v)

        return (fact * self.power(sizes, self.MOD - 2) - 1) % self.MOD

    def power(self, b: int, e: int) -> int:
        r = 1
        b %= self.MOD

        while e > 0:
            if e & 1:
                r = r * b % self.MOD
            b = b * b % self.MOD
            e >>= 1

        return r