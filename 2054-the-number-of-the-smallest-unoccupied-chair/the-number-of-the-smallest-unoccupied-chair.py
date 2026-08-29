import heapq
from collections import deque

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        N = len(times)
        T = times[targetFriend]
        times.sort(key = lambda time: (time[0], time[1]))

        chairs = []

        free = [i for i in range(N)]
        heapq.heapify(free)

        for s, e in times:
            while chairs and chairs[0][0] <= s:
                heapq.heappush(free, heapq.heappop(chairs)[1])
            
            if [s, e] == T:
                return free[0]
            
            heapq.heappush(chairs, (e, free[0]))
            heapq.heappop(free)
        
        return None