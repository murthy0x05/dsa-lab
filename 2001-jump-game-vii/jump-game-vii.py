class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        N = len(s)

        visited = [0]
        def lb(target):
            low, high = 0, len(visited) - 1
            
            while low <= high:
                mid = low + ((high - low) >> 1)
                if visited[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
            
            return low
        
        for i in range(1, N):
            if s[i] == '1':
                continue
            
            p1 = i - maxJump
            p2 = i - minJump
            idx = lb(p1)
            if idx == len(visited):
                return False
            if visited[idx] <= p2:
                visited.append(i)
        
        return True if visited[-1] == (N - 1) else False


            