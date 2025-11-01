/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private int n;
    public ListNode modifiedList(int[] nums, ListNode head) {
        this.n = nums.length;

        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < n; i++) {
            seen.add(nums[i]);
        }

        ListNode dummy = new ListNode();
        ListNode node = dummy;
        for (ListNode curr = head; curr != null; curr = curr.next) {
            if (!seen.contains(curr.val)) {
                node.next = curr;
                node = node.next;
            }
        }
        node.next = null;

        ListNode result = dummy.next;

        return result;
    }
}