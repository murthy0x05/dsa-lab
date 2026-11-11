class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        if need1 < need2:
            if costBoth <= cost1 + cost2:
                return min(costBoth * need2, costBoth * need1 + (need2 - need1) * cost2)
            else:
                return cost1 * need1 + cost2 * need2
        else:
            if costBoth <= cost1 + cost2:
                return min(costBoth * need1, costBoth * need2 + (need1 - need2) * cost1)
            else:
                return cost1 * need1 + cost2 * need2
