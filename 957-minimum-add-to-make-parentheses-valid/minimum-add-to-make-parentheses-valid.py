class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        N = len(s)

        moves = 0
        o, c = 0, 0
        for i in range(N):
            if s[i] == '(':
                o += 1
            else:
                c += 1

            if o < c:
                moves += 1
                o += 1
        
        return moves + abs(o - c)