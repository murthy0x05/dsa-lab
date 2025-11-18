class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)

        i = 0
        while i < n:
            if 1 == bits[i]:
                i += 1
            elif i == n - 1:
                return True
            i += 1

        return False