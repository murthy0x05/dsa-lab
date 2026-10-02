class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = {}
        max_freq = 0
        n = len(s)
        for i in s:
            freq[i] = freq.get(i, 0) + 1
            if freq[i] > max_freq:
                max_freq = freq[i]

        if max_freq > (n+1) // 2:
            return ""

        heap = [(-freq[i], i) for i in freq]
        heapq.heapify(heap)

        res = []
        while len(heap) > 1:
            count_1, char_1 = heapq.heappop(heap)
            count_2, char_2 = heapq.heappop(heap)
            res.append(char_1)
            res.append(char_2)

            if count_1 + 1 < 0:
                heapq.heappush(heap, (count_1+1, char_1))

            if count_2 + 1 < 0:
                heapq.heappush(heap, (count_2+1, char_2))

        if heap:
            count, char = heapq.heappop(heap)
            if count == -1:
                res.append(char)
            else:
                return ""
        return "".join(res)