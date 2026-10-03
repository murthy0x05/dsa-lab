class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        N = len(s)

        st = []
        opp = [-2 for _ in range(N)]
        for i in range(N):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                if st:
                    opp[st[-1]] = i
                    opp[i] = st[-1]
                    st.pop()
                else:
                    opp[i] = -1

        for idx in st:
            opp[idx] = -1
        
        return ''.join([s[i] for i in range(N) if opp[i] != -1])