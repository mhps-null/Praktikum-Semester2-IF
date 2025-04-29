# Input
angka=str(input("Masukkan bilangan 4 digit: "))

# Proses
if (angka[0]>angka[1] and angka[1]>angka[2] and angka[2]>angka[3])or(angka[0]<angka[1] and angka[1]<angka[2] and angka[2]<angka[3]):
    if (int(angka[0:2]))-(int(angka[2:5]))>=30:
        bilangan="Gamma"
    else: bilangan="Alfa"
elif (int(angka[0:2]))-(int(angka[2:5]))>=30:
    bilangan="Beta"
else: bilangan="Delta"

# Output
print(bilangan)