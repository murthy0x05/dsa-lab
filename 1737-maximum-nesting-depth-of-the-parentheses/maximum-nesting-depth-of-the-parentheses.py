class Solution:
    def maxDepth(self, s: str) -> int:
        N = len(s)

        cnt = 0
        largest = 0
        for i in range(N):
            if s[i] == '(':
                cnt += 1
                largest = max(largest, cnt)
            elif s[i] == ')':
                cnt -= 1

        return largest