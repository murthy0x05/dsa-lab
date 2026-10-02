class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        N = len(s)

        st = []
        opp = [-1 for _ in range(N)]
        for i in range(N):
            if s[i] == '(':
                st.append(i)
            else:
                opp[st[-1]] = i
                opp[i] = st[-1]
                st.pop()
        
        def f (l, r):
            if r - l == 1:
                return 1

            mult = False
            if opp[l] == r:
                l += 1
                r -= 1
                mult = True

            
            i = l
            score = 0
            while i <= r:
                score += f (i, opp[i])
                i = opp[i] + 1
            
            if mult:
                return 2 * score

            return score

        return f(0, N - 1)
            

        