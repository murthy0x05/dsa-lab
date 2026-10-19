class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def f (i, j):
            if j < 0:
                return i < 0
            if i < 0:
                if j >= 1 and p[j] == '*':
                    return f(i, j - 2)
                else:
                    return False

            if p[j] == '*':
                if s[i] == p[j - 1] or p[j - 1] == '.':
                    return f(i - 1, j - 2) or f(i - 1, j) or f(i, j - 2)
                else:
                    return f(i, j - 2)
            elif p[j] == '.':
                return f(i - 1, j - 1)
            else:
                return p[j] == s[i] and f(i - 1, j - 1)

        return f(len(s) - 1, len(p) - 1)