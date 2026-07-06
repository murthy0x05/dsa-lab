class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        N = len(intervals)

        intervals.sort(key = lambda interval: (interval[0], -interval[1]))
        
        prev = -1
        result = 0
        for i in range(N):
            if intervals[i][1] > prev:
                result += 1
                prev = intervals[i][1]
        
        return result