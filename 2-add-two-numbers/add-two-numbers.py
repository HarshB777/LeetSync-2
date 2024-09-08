# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # Start with a dummy node to simplify logic
        current = dummy  # This will be used to build the result linked list
        carry = 0  # Initialize carry

        # Traverse both linked lists
        while l1 or l2 or carry:
            # Get values from l1 and l2, or use 0 if the node is null
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            total_sum = val1 + val2 + carry

            # Update carry for next digit
            carry = total_sum // 10

            # Create new node with the digit and add to the result list
            current.next = ListNode(total_sum % 10)
            current = current.next

            # Move to the next nodes in l1 and l2 if available
            if l1: 
                l1 = l1.next
            if l2: 
                l2 = l2.next

        # Return the next node of the dummy, which is the head of the result linked list
        return dummy.next
