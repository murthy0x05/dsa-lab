class Solution:
    def minimumPushes(self, word: str) -> int:
        N = len(word)

        i = 1
        result = 0
        while N > 0:
            result += i * min(N, 8)
            N -= 8

            i += 1

        return result