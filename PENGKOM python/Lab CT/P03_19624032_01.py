# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 21/11/2024
# Deskripsi : Menentukan diskriminan

# Program mencari diskriminan
# Spesifikasi : menentukan diskriminan dari input fungsi a,b,c

# Kamus
# a = float
# b = float
# c = float
# d = float

# Input
a=float(input("Masukkan nilai a: "))
b=float(input("Masukkan nilai b: "))    # Input a,b,c
c=float(input("Masukkan nilai c: "))

# Process
def diskriminan(a,b,c): # Ini Fungsi
    d=(b**2)-(4*(a*c))  # Hitung Diskriminan
    return d

def hasil(d):   # Ini Prosedur
    print(f"Nilai diskriminan {d}")
    if d>0:     # Jika diskriminan lebih dari 0
        print("Persamaan kuadrat memiliki akar berbeda")    # hasil akar beda
    elif d<0:   # Jika diskriminan kurang dari 0
        print("Persamaan kuadrat tidak memiliki akar real") # hasil akar tidak real
    else:   # Jika diskriminan 0
        print("Persamaan kuadrat memiliki akar kembar")     # hasil akar kembar

#  Output
d=diskriminan(a,b,c)
hasil(d)