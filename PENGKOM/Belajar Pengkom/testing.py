l1 = [2,4,3]
l2 = [5,6,4]
total=0

def get_length(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

lenl1=get_length(l1)
lenl2=get_length(l2)

for i in range(lenl1):
    belakang=10**i
    l1[i] = l1[i]*belakang
    total+=l1[i]

for i in range(lenl2):
    belakang=10**i
    l2[i] = l2[i]*belakang
    total+=l2[i]

total = str(total)
total = total[::-1]
total = int(total)
arr=[int(digits) for digits in str(total)]
print(lenl1)