class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        N = len(s)

        cnt = 0
        la, lb, lc = -1, -1, -1
        for i in range(N):
            if s[i] == 'a':
                la = i
            elif s[i] == 'b':
                lb = i
            else:
                lc = i
            
            cnt += min(la, lb, lc) + 1
        
        return cnt
