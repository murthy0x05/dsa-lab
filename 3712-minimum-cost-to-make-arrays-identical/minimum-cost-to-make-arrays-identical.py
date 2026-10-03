class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        N = len(arr)

        smallest = 0
        for i in range(N):
            smallest += abs(arr[i] - brr[i])

        arr.sort()
        brr.sort()
        cost = 0
        for i in range(N):
            cost += abs(arr[i] - brr[i])
    
        return min(smallest, cost + k)