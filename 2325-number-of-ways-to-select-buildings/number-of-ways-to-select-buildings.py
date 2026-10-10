class Solution:
    def numberOfWays(self, s: str) -> int:
        N = len(s)
        
        result = 0
        cnt0, cnt1 = 0, 0
        cnt10, cnt01 = 0, 0
        for i in range(N):
            if s[i] == '0':
                result += cnt01
                cnt10 += cnt1
                cnt0 += 1
            else:
                result += cnt10
                cnt01 += cnt0
                cnt1 += 1
        
        return result