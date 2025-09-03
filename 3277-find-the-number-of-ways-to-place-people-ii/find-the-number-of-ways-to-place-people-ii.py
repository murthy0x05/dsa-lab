class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort(key = lambda point: (point[0], -point[1]))

        result = 0
        for i in range(n):
            y = float("-inf")
            for j in range(i + 1, n):
                if points[i][1] >= points[j][1] and points[j][1] > y:
                    result += 1
                    y = points[j][1]

        return result