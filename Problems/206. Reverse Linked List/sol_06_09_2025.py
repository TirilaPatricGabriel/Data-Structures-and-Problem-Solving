# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        if not head.next:
            return head

        prev = head
        cur = head.next
        prev.next = None

        while cur:
            nextt = cur.next
            cur.next = prev
            prev = cur
            cur = nextt

        return prev