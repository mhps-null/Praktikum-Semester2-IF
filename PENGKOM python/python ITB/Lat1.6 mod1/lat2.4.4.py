panjang_A=(int(input("Masukkan panjang A: ")))
counts1=[0 for i in range(10)]

for i in range (panjang_A):
    A=int(input(f"Masukkan elemen A ke {i+1}"))
    if A==1:
        counts1[0]+=1
    if A==2:
        counts1[1]+=1
    if A==3:
        counts1[2]+=1
    if A==4:
        counts1[3]+=1
    if A==5:
        counts1[4]+=1
    if A==6:
        counts1[5]+=1
    if A==7:
        counts1[6]+=1
    if A==8:
        counts1[7]+=1
    if A==9:
        counts1[8]+=1
    if A==10:
        counts1[9]+=1

panjang_B=(int(input("Masukkan panjang B: ")))

for i in range (panjang_B):
    B=int(input(f"Masukkan elemen A ke {i+1}"))
    if B==1:
        counts1[0]-=1
    if B==2:
        counts1[1]-=1
    if B==3:
        counts1[2]-=1
    if B==4:
        counts1[3]-=1
    if B==5:
        counts1[4]-=1
    if B==6:
        counts1[5]-=1
    if B==7:
        counts1[6]-=1
    if B==8:
        counts1[7]-=1
    if B==9:
        counts1[8]-=1
    if B==10:
        counts1[9]-=1

x=counts1.count(0)
if x==10:
    print("iya")
else: print("Bukan")