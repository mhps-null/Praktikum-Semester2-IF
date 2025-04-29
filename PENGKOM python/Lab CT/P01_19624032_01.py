# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 17/10/2024
# Deskripsi : Menentukan uang mana yang lebih banyak ketika dikonversikan

# Program konversi mata uang
# Spesifikasi : menentukan konversi uang mana yang lebih besar

# Kamus
# Peng : Int
# Kom : Int
# KonversiPeng : Int
# KonversiKom : Int

# Algoritma
Peng=(int(input("Banyak uang Peng yang ditawarkan: ")))
Kom=(int(input("Banyak uang Kom yang ditawarkan:")))
KonversiPeng=(int(input("Konversi mata uang Peng ke rupiah: ")))
KonversiKom=(int(input("Konversi mata uang Kom ke rupiah: ")))

TotalPeng=Peng*KonversiPeng
TotalKom=Kom*KonversiKom

if TotalPeng>TotalKom:
    print("Adik Tuan Leo memilih uang Peng.")

elif TotalPeng==TotalKom:
    print("Adik Tuan Leo memilih uang Peng atau Kom sama saja.")

else:
    print("Adik Tuan Leo memilih uang Kom.")