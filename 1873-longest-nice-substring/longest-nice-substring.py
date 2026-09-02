class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        N = len(s)

        for L in range(N, -1, -1):
            for l in range(N - L + 1):
                S = s[l : (l + L)]
                for c in string.ascii_lowercase:
                    if c in S and c.upper() not in S:
                        break
                    if c.upper() in S and c not in S:
                        break
                else:
                    return S
        
        return ""