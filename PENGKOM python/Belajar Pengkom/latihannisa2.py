banyaksiswa=int(input("Masukkan banyak siswa: "))
nilaisiswa=[0 for i in range (banyaksiswa)]
bisa=[0 for i in range (banyaksiswa)]

for i in range (banyaksiswa):
    nilaisiswa[i]=int(input(f"Masukkan siswa NIM ke {i+1} "))

deb=int(input("Masukkan NIM nona Deb: "))-1
x=int(input("Masukkan batas x: "))
print(nilaisiswa)
print(deb+x)
print(deb-x)
for i in range(deb-x,deb+x+1,1):
    if nilaisiswa[i]>nilaisiswa[deb]:
        print (f"Mahasiswa bisa: {i+1}")