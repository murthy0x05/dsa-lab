class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        parens = []

        self.paren = ""
        self.largest = 0
        def f (i, o, c):
            if o < c:
                return
            nonlocal parens
            if i == len(s):
                if o == c:
                    if self.largest < o + c:
                        self.largest = o + c
                        parens = [self.paren]
                    elif self.largest == o + c:
                        parens.append(self.paren)
                    
                return 

            self.paren += s[i]
            f (i + 1, o + (s[i] == '('), c + (s[i] == ')'))
            self.paren = self.paren[:-1]
            
            if s[i] in "()":
                if len(self.paren) == 0 or self.paren[-1] != s[i]:
                    f (i + 1, o, c)

        f (0, 0, 0)
        return parens if parens else [""]