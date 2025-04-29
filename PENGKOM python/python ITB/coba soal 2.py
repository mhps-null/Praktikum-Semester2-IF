angkaN=int(input())

if angkaN <= 0:
    print ("tidak ada")
x=0
i = angkaN/5
x +=(5*i)
total=i*5 + x

print(total+x)

# Membaca input N dari pengguna
N = int(input("Masukkan nilai N: "))

# Inisialisasi variabel untuk menyimpan total jumlah kelipatan 5
total = 0

# Menggunakan loop untuk menjumlahkan kelipatan 5 antara 1 hingga N
for i in range(5, N + 1, 5):
    total += i

# Menampilkan hasil
print(f"Jumlah kelipatan 5 dari 1 hingga {N} adalah {total}")
