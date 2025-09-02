from typing import List
# for type hints such as List[List[int]] -> int

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key = lambda point: (point[0], -point[1]))

        n = len(points)
        result = 0
        for i in range(0, n, 1):
            y = float("-inf")
            for j in range(i + 1, n, 1):
                if points[i][1] >= points[j][1] and points[j][1] > y:
                    result += 1
                    y = points[j][1]
        
        return result