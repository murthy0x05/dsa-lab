class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        N = len(arr)
        dp = [False for _ in range(N)]
        
        dp[start] = True
        q = deque([start])
        while q:
            curr = q.popleft()
            if arr[curr] == 0:
                return True
            dp[curr] = True

            if curr - arr[curr] >= 0 and curr - arr[curr] < N and not dp[curr - arr[curr]]:
                dp[curr - arr[curr]] = True
                q.append(curr - arr[curr])
            if curr + arr[curr] >= 0 and curr + arr[curr] < N and not dp[curr + arr[curr]]:
                dp[curr + arr[curr]] = True
                q.append(curr + arr[curr])

        return False
