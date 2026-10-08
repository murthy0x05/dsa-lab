class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        N = len(nums)

        occ = Counter(nums)
        occ = sorted(occ.items(), key = itemgetter(0))
        sz = len(occ)

        @cache
        def f (i, took):
            if i == sz:
                return 0

            take = 0
            skip = f(i + 1, False)
            if not took or took and occ[i][0] - 1 != occ[i - 1][0]:
                take = occ[i][0] * occ[i][1] + f(i + 1, True)
            
            return max(take, skip)

        return f(0, False)