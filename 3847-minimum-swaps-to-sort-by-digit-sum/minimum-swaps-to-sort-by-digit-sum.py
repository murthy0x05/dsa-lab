class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        N = len(nums)

        ids = [i for i in range(N)]
        ids.sort(key = lambda id: (sum([int(val) for val in str(nums[id])]), nums[id]))

        print(ids)
    
        swaps = 0
        for i in range(N):
            if ids[i] != i:
                head = i

                V = 1
                curr = ids[head]
                ids[head] = head
                while curr != head:
                    next = ids[curr]
                    ids[curr] = curr
                    curr = next
                    V += 1
                
                print(V)
                swaps += V - 1
    
        return swaps