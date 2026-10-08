class Solution:
    def isSubSeq(self, p, s):
        i, j = 0, 0

        while i < len(p) and j < len(s):
            if p[i] == s[j]:
                i += 1
            
            j += 1
        
        return i == len(p)

    def camelMatch(self, queries: list[str], pattern: str) -> list[bool]:
        result = []

        capsP = [0] + [i for i in range(len(pattern)) if 'A' <= pattern[i] <= 'Z'] + [len(pattern)]
        for query in queries:
            capsQ = [0] + [i for i in range(len(query)) if 'A' <= query[i] <= 'Z'] + [len(query)]
            if len(capsP) != len(capsQ):
                result.append(False)
            else:
                for j in range(1, len(capsP)):
                    if not self.isSubSeq(pattern[capsP[j - 1]:capsP[j]], query[capsQ[j - 1]:capsQ[j]]):
                        result.append(False)
                        break
                else:
                    result.append(True)

        return result