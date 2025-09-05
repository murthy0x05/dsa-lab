class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for op in range(1, 61, 1):
            diff = num1 - op * num2
            if diff < op: continue
            if diff.bit_count() <= op:
                return op

        return -1