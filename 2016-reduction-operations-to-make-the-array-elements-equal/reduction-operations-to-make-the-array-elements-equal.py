class Solution:
    def reductionOperations(self, nums: list[int]) -> int:
        N = len(nums)

        occ = Counter(nums)
        occ = sorted(occ.items(), key = itemgetter(0), reverse = True)

        result = 0
        prev = occ[0][1]
        for i in range(1, len(occ)):
            result += prev
            prev += occ[i][1]
        
        return result