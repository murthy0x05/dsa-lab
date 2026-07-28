class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        N = len(nums)

        result = nums[k]
        l, r = k - 1, k + 1
        Min = nums[k]
        while l >= 0 and r < N:
            if nums[l] > Min:
                l -= 1
            elif nums[r] > Min:
                r += 1
            else:
                if nums[l] < nums[r]:
                    Min = min(Min, nums[r])
                    r += 1
                else:
                    Min = min(Min, nums[l])
                    l -= 1
            
            result = max(result, (r - l - 1) * Min)
        while l >= 0:
            Min = min(Min, nums[l])
            l -= 1

            result = max(result, (r - l - 1) * Min)
        while r < N:
            Min = min(Min, nums[r])
            r += 1

            result = max(result, (r - l - 1) * Min)

        return result