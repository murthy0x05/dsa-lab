class Solution:
    def longestValidParentheses(self, s: str) -> int:
        N = len(s)

        
        st = []
        opp = [0 for _ in range(N)]
        for i, c in enumerate(s):
            if c == '(':
                st.append(i)
            else:
                if st:
                    opp[i] = st[-1]
                    opp[st[-1]] = i
                    st.pop()
                else:
                    opp[i] = -1
        
        for idx in st:
            opp[idx] = -1

        curr = 0
        longest = 0
        
        i = 0
        while i < N:
            if opp[i] == -1:
                curr = 0
                i += 1
            else:
                curr += opp[i] - i + 1
                longest = max(longest, curr)

                i = opp[i] + 1

        return longest