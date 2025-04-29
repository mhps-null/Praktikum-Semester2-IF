"""
Nilai 85-100 dikonversi menjadi "A".
Nilai 70-84 dikonversi menjadi "B".
Nilai 55-69 dikonversi menjadi "C".
Nilai 40-54 dikonversi menjadi "D".
Nilai 0-39 dikonversi menjadi "E".
"""

nilai = int(input("Input nilai anda : "))

if nilai <= 100 and nilai >=0:
    if nilai >= 0 and nilai <=39:
            print("Indeks nilai anda adalah E")
    elif nilai >=40 and nilai <=54:
            print("Indeks nilai anda adalah D")
    elif nilai >=55 and nilai <=69:
            print("Indeks nilai anda adalah C")
    elif nilai >=70 and nilai <= 84:
            print("Indeks nilai anda adalah B")
    else :
            print("Indeks nilai anda adalah A")
else: print ("Nilai anda tidak valid")