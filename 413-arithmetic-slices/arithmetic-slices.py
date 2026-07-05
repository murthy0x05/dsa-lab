class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        N = len(nums)

        result = 0
        prev, pdiff = 0, 1000000
        i = 2
        while i < N:
            diff = nums[i] - nums[i - 1]
            if diff == pdiff:
                prev += 1
                result += prev
            else:
                j = i - 1
                while j > 0 and (nums[j] - nums[j - 1]) == diff:
                    j -= 1
                
                pdiff = 10000000
                if i - j >= 2:
                    result += i - j - 1
                    prev = i - j - 1
                    pdiff = diff
            i += 1

        return result