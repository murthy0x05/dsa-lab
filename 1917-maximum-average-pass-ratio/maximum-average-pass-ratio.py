class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        pq = []

        for i in range(n):
            heapq.heappush(pq, (-(((classes[i][0] + 1) / (classes[i][1] + 1)) - (classes[i][0] / classes[i][1])), i))

        while extraStudents > 0:
            i = pq[0][1]
            classes[i][0] += 1
            classes[i][1] += 1
            extraStudents -= 1
            heapq.heappop(pq)
            heapq.heappush(pq, (-(((classes[i][0] + 1) / (classes[i][1] + 1)) - (classes[i][0] / classes[i][1])), i))

        ans = 0.0
        for c in classes:
            ans += c[0] / c[1]

        return ans / n
