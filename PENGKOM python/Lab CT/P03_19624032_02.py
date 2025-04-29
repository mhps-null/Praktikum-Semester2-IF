# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 21/11/2024
# Deskripsi : Mencari tahu mesin bekerja berapa kali

# Program mesin bekerja
# Spesifikasi : menentukan berapa kali mesin bekerja sesuai dengan aturan ganjil dan genap yang ditetapkan soal

# Kamus
# angka = int


# Input
angka=str(input("Masukkan angka: "))

# Process
def ubahkeint(angka):       # Fungsi untuk mengubah str menjadi int
    array=[0 for _ in range (len(angka))]
    for i in range (len(angka)):
        array[i]=angka[i]
        array[i]=int(array[i])
    return array

def ganjil(array):      # Fungsi untuk urutan ganjil
    jumlah=0
    for j in range (len(array)-1,-1,-2):
        jumlah+=array[j]
    return jumlah

def genap(array):       # Fungsi untuk urutan genap
    jumlah=0
    for j in range (len(array)-2,-1,-2):
        jumlah+=array[j]
    return jumlah

# Output
jumlah=(int(ganjil(ubahkeint(angka))))  # Jumlahnya
if jumlah>9:            # Jika jumlahnya lebih dari satu digit maka
    jumlah=str(jumlah)      
    print((genap(ubahkeint(jumlah))))       # Di operasikan lagi sampai satu digit
else: print(jumlah)