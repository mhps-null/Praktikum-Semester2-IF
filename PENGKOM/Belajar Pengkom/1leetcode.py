numsLength=int(input("Masukkan panjang list: "))
angka=input().split()
angka=[int(i) for i in angka]
target=int(input("Masukkan target: "))

for i in range (numsLength):
    for j in range (i+1,numsLength):
        if angka[i]+angka[j]==target:
            print(i,j)
            break
        