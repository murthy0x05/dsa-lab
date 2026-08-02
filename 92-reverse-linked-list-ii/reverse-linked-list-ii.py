# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head

        L = None

        i = 1
        curr = head
        prev = None
        LP = None
        while i <= right:
            if i + 1 == left:
                LP = curr
            
            if i == left:
                L = curr

            if left <= i <= right:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
            else:
                curr = curr.next
            
            if i == right:
                if LP:
                    LP.next = prev
                else:
                    head = prev
                L.next = curr
            
            i += 1

        return head