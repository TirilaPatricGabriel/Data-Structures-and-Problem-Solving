# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head
        
        pos = {}

        cur = head
        nr = 0
        while cur:
            pos[nr] = cur
            nr+=1
            cur = cur.next

        del_pos = nr - n - 1

        if del_pos == -1:
            head = head.next
            return head

        node = pos[del_pos]
        node.next = node.next.next if node.next else None

        return head
        
        