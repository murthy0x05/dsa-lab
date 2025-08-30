class Solution:
    def trap(self, height: List[int]) -> int:
        l_max, r_max = height[0], height[-1]
        l, r = 1, len(height) - 2
        water = 0
        while l <= r:
            if l_max < r_max:
                water += max(0, l_max - height[l])
                l_max = max(height[l], l_max)
                l += 1
            else:
                water += max(0, r_max - height[r])
                r_max = max(height[r], r_max)
                r -= 1
        
        return water

                


        