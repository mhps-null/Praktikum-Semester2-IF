class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def get_length(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

# Contoh penggunaan:
node3 = ListNode(7)
node2 = ListNode(0, node3)
node1 = ListNode(8, node2)

print(get_length(node1))  # Output: 3
