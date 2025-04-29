# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 31/10/2024
# Deskripsi : cari angka

# Program mencari angka yang bisa dibagi digit terakhir
# Spesifikasi : Mencari angka pada rentang tertentu yang bisa dibagi digit terakhir

# Kamus
# angka=int
# A=str
# B=str

angka=[0 for i in range (1001)]     # Tempat array semua bilangan dari 1-1000
A=str(input("Masukkan nilai A: "))  
B=str(input("Masukkan nilai B: "))
angkabisa=0     # Deklarasi berapa banyak angka yang bisa dibagi digit terakhir, dimulai dari 0

for i in range (1001):  # Memasukkan semua bilangan 1-1000 ke array
    angka[i]=i

A=int(A)
B=int(B)
for j in range (A,B+1):        # Mengambil angka pada rentang [A,B]
    digitakhir=angka[j]         # Deklarasi digit akhir
    digitakhir=str(digitakhir)
    digitakhir=digitakhir[-1]       # Mengambil digit terakhir angka
    digitakhir=int(digitakhir)
    if digitakhir!=0:
        if angka[j]%digitakhir==0:      # Mencari tahu apakah angkanya bisa dibagi digit terakhir
            angkabisa+=1
print(angkabisa)