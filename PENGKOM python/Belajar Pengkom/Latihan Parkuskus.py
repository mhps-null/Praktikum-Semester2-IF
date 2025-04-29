# Program fungsi sigma matematika
# Deskripsi: Sigma i=1 sampai n dari ax**i+b

# Kamus

# Algoritma

# Input
a=int(input("Masukkan a: "))
b=int(input("Masukkan b: "))
x=int(input("Masukkan x: "))
n=int(input("Masukkan n: "))

# Proses
hasil=0

for i in range (1,n+1):
    hasil+=(a*(x**i))+b

# Output
print(hasil)