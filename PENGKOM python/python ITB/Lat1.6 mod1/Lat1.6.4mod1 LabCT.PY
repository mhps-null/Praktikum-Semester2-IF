koordinat=int(input("koordinat= "))
a=int(input("a= "))
b=int(input("b= "))

if koordinat%2==0:
    k=a*b
    kiri=k//2
    kanan=(k//2)+1
    print(koordinat+(a*kanan)-(b*kiri))