# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head
        prev = None

        while fast and fast.next:
            fast = fast.next.next
            follow = slow.next
            slow.next = prev
            prev = slow
            slow = follow
        
        largest = -1
        while prev:
            largest = max(largest, prev.val + slow.val)
            prev = prev.next
            slow = slow.next
        
        return largest

