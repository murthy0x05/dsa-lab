class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        N = len(weight)
        
        result = 0

        largest = float('-inf')
        for i in range(N):
            if weight[i] < largest:
                result += 1

                largest = float('-inf')
            else:
                largest = weight[i]

        return result