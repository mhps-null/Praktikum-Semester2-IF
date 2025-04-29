# suit=input("string: ")
suit=list("GGGGKKKK")

def aturansuit(a,b):
    if a=="G" and b=="K":
        return a
    elif a=="G" and b=="B":
        return b
    elif a=="K" and b=="G":
        return b
    elif a=="K" and b=="B":
        return a
    elif a=="B" and b=="G":
        return a
    elif a=="B" and b=="K":
        return b
    elif a==b:
        return a

for _ in range(0,len(suit),2):
    arr=[0 for L in range (len(suit))]
    arr[_]=(aturansuit(str(suit[_]), str(suit[_+1])))
    for _ in range(0,len(arr),2):
        aturansuit(arr[_],(arr[_]))
        arr[_]=(aturansuit(str(suit[_]), str(suit[_+1])))
        for _ in range(0,len(suit),2):
            aturansuit(suit[_],(suit[_+1]))
            arr[_]=(aturansuit(str(suit[_]), str(suit[_+1])))

print(arr)
for _ in range (0,len(arr),4):
    arrlagi=[0 for K in range (len(arr))]
    arrlagi[_]=aturansuit(arr[_],arr[_+2])
    print(arrlagi)

