class Solution:
    def isValid(self, s: str) -> bool:
        opp = {')':  '(', "}": "{", "]": "["}

        st = []
        for c in s:
            if c in opp:
                if not st or st[-1] != opp[c]:
                    return False
                st.pop()
            else:
                st.append(c)
        
        return not st