# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)

        current = dummy

        carry = 0

        while l1 or l2 or carry:
            digit1 = l1.val if l1 else 0
            digit2 = l2.val if l2 else 0

            cs = digit1 + digit2 + carry

            carry = cs // 10


            to_add = ListNode(cs % 10)
            current.next = to_add
            current = current.next


            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

    

        return dummy.next






        