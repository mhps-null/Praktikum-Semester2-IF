# Program ganjil/genap?
# Spesifikasi : mencari tahu apakah angka yang diinput genap atau ganjil

# KAMUS

# Algoritma
angka=int(input("masukkan nilai N: "))
if (angka%2)==0:
    if angka>0:
        print(f"{angka} bilangan positif genap")
    if angka<0:
        print(f"{angka} bilangan negatif genap")
elif angka>0:
    print (f"{angka} bilangan positif ganjil")
else:
    print (f"{angka} bilangan negatif ganjil")