"""cek angka positif atau negatif, lalu cek ganjil atau genap"""

a = int(input("Masukkan angka : "))
if a>0: 
    print(f"angka anda {a} adalah positif")
elif a<0: 
    print(f"angka anda {a} adalah negatif")
else:
    print(f"angka anda sama dengan 0")

if a%2==0:
    print(f"angka anda {a} adalah genap")
else:
    print(f"angka anda {a} adalah ganjil")

