class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        window = SortedList()
        costs = []
        cost = 0
        
        def change(num):
            return abs(num - window[len(window) // 2])

        removals = iter(nums)
        for num in nums:

            if len(window) % 2:
                cost += change(num)
                window.add(num)
            else:
                window.add(num)
                cost += change(num)

            if len(window) == x:
                costs.append(cost)

                old = next(removals)
                if len(window) % 2:
                    cost -= change(old)
                    window.remove(old)
                else:
                    window.remove(old)
                    cost -= change(old)

        minCost = repeat(0)
        for _ in range(k):
            minCost = list(accumulate(map(add, minCost, costs), min))
            del costs[:x]
        return minCost[-1]