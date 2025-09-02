class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        result = []
        f = set(friends)
        for id in order:
            if id in f:
                result.append(id)

        return result