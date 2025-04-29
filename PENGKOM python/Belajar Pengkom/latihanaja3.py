angka=int(input("Masukkan angka : "))
angGanjil=(angka%2==1)
total=0

while angGanjil:
    angka=int(input("Masukkan angka : "))
    total+=angGanjil+angka

print(total)