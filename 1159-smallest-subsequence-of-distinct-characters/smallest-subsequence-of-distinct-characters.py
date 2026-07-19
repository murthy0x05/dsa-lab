class Solution:
    def smallestSubsequence(self, s: str) -> str:
        N = len(s)

        lid = [-1 for _ in range(26)]
        for i in range(N):
            lid[ord(s[i]) - 97] = i

        mst = []
        visited = [False for _ in range(26)]
        for i in range(N):
            if visited[ord(s[i]) - 97]:
                continue

            while mst and mst[-1] > s[i] and lid[ord(mst[-1]) - 97] > i:
                visited[ord(mst[-1]) - 97] = False
                mst.pop()
            mst.append(s[i])
            visited[ord(mst[-1]) - 97] = True
        
        return ''.join(mst)