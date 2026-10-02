class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        self.n = n
        parens = []

        self.paren = ""
        def f (o, c):
            if o > self.n or c > self.n or o < c:
                return
            if o == self.n and c == self.n:
                parens.append(self.paren)
                return
            
            self.paren += '('
            f(o + 1, c)
            self.paren = self.paren[:-1]

            self.paren += ')'
            f(o, c + 1)
            self.paren = self.paren[:-1]
        
        f(0, 0)
        return parens