class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)

        z, nz = 0, 0
        while z < N and nz < N:
            if nums[nz] == 0:
                nz += 1
            elif nums[z] != 0:
                z += 1
            else:
                if nz > z:
                    nums[nz], nums[z] = nums[z], nums[nz]
                    z += 1
                    nz += 1
                else:
                    nz += 1