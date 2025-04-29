halaman = int(input("Masukkan banyak halaman : "))
bilangan = int(input("Masukkan bilangan : "))
hasil = 0

for i in range(1,halaman+1):
    while i%bilangan==0:
        hasil+=i

print(hasil)