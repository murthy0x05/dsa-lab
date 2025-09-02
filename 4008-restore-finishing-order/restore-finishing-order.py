class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        result = []
        for id in order:
            if id in friends:
                result.append(id)

        return result