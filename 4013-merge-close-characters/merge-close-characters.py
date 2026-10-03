class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        N = len(s)

        occ = {}
        result = ""
        for i in range(N):
            if s[i] in occ:
                if len(result) - occ[s[i]] > k:
                    occ[s[i]] = len(result)
                    result += s[i]
            else:
                occ[s[i]] = len(result)
                result += s[i]

        return result