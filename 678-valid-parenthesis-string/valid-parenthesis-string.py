from functools import cache

class Solution:
    def checkValidString(self, s: str) -> bool:
        N = len(s)

        @cache
        def f (i, diff):
            if diff < 0:
                return False
            if i == N:
                return diff == 0

            if s[i] == '(':
                return f(i + 1, diff + 1)
            elif s[i] == ')':
                return f(i + 1, diff - 1)
            else:
                return f(i + 1, diff) or f(i + 1, diff + 1) or f(i + 1, diff - 1)
        
        return f (0, 0)