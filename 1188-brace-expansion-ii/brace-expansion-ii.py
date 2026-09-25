class Solution:
    def braceExpansionII(self, E: str) -> list[str]:
        N = len(E)
        
        words = set()
        def f (word):
            cid = word.find('}')

            if cid == -1:
                words.add(word)
                return 

            oid = word.rfind('{', 0, cid)

            inside = word[(oid + 1):(cid)]
            for part in inside.split(','):
                f(word[:oid] + part + word[(cid + 1):])

        f(E)

        return sorted(list(words))