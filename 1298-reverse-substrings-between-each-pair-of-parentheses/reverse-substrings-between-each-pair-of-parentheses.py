class Solution:
    def reverseParentheses(self, s: str) -> str:
        def f(S):
            r = S.find(')')

            if r == -1:
                return S
            
            l = S.rfind('(', 0, r)

            return f(S[:l] + S[(l + 1):(r)][::-1] + S[(r + 1):])

        return f(s)