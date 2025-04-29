# Input
n=(int(input("Masukkan n: ")))

# Proses
angka=[0 for i in range(n+1)]
angka[0]=0
angka[1]=1

for i in range(2,n+1):
    angka[i]=angka[i-1]+angka[i-2]

# Output
print (angka)