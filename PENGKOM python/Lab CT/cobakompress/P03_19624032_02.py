# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 21/11/2024
# Deskripsi : Mencari tahu mesin bekerja berapa kali

# Program mesin bekerja
# Spesifikasi : menentukan berapa kali mesin bekerja sesuai dengan aturan ganjil dan genap yang ditetapkan soal

# Kamus
# 

# Input
angka=str(input("Masukkan angka: "))

def ubahkeint(angka):
    array=[0 for _ in range (len(angka))]
    for i in range (len(angka)):
        array[i]=angka[i]
        array[i]=int(array[i])
    return array

def ganjil(array):
    jumlah=0
    for j in range (len(array)-1,-1,-2):
        jumlah+=array[j]
    return jumlah

def genap(array):
    jumlah=0
    for j in range (len(array)-2,-1,-2):
        jumlah+=array[j]
    return jumlah

jumlah=(int(ganjil(ubahkeint(angka))))
if jumlah>9:
    jumlah=str(jumlah)
    print((genap(ubahkeint(jumlah))))
else: print(jumlah)