class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        K = defaultdict(lambda: "?")

        for k, v in knowledge:
            K[k] = v
        
        N = len(s)

        i = 0
        oid, cid = -2, -1
        result = ""
        while i < N:
            if s[i] == '(':
                oid = i
            elif s[i] == ')':
                cid = i

                result += K[s[(oid + 1):(cid)]]
            else:
                if oid < cid:
                    result += s[i]
                    
            i += 1

        return result