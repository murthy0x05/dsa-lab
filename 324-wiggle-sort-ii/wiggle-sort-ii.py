class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        arr = [0] * N
        
        j = (N - 1) >> 1
        nums.sort()
        for i in range(0, N, 2):
            arr[i] = nums[j]
            j -= 1

        j = N - 1
        for i in range(1, N, 2):
            arr[i] = nums[j]
            j -= 1
        
        for i in range(N):
            nums[i] = arr[i]  