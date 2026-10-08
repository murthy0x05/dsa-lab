class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        N = len(nums1)

        K = k1 + k2
        numsa = [abs(nums1[i] - nums2[i]) for i in range(N)]

        numsa.sort(key = lambda val: -val)
        cnt = Counter(numsa)
        cnt = list(map(list, sorted(cnt.items(), key = itemgetter(0), reverse = True)))

        result = 0
        curr = cnt[0]
        for i in range(1, len(cnt)):
            if K > 0:
                need = (curr[0] - cnt[i][0]) * curr[1]
                if K > need:
                    curr[0] = cnt[i][0]
                    curr[1] += cnt[i][1]
                    K -= need
                else:
                    avg = K // curr[1]
                    curr[0] -= avg
                    left = K % curr[1]

                    result += (curr[0] ** 2) * (curr[1] - left)
                    result += ((curr[0] - 1) ** 2) * left
                    curr = None
                    K = 0

                    result += (cnt[i][0] ** 2) * cnt[i][1]
            else:
                result += (cnt[i][0] ** 2) * cnt[i][1]

        if curr:
            need = curr[0] * curr[1]
            if K < need:
                avg = K // curr[1]
                curr[0] -= avg
                left = K % curr[1]

                result += (curr[0] ** 2) * (curr[1] - left)
                result += ((curr[0] - 1) ** 2) * left
                curr = None
                K = 0

        return result