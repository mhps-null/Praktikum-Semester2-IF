# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 31/10/2024
# Deskripsi : pesan rahasia

banyakhuruf=int(input(" Masukkan jumlah huruf pada kamus rahasia: "))       # Banyak huruf yang akan dirahasiakan
hurufasli=[0]*100       # Membuat tempat huruf asli
hurufrahasia=[0]*100        # Membuat tempat huruf rahasia
for i in range (banyakhuruf):
    hurufasli[i]=input(f" Masukkan huruf biasa ke-{i+1} ")          # Menginput huruf biasa sebanyak i
    hurufrahasia[i]=input(f" Masukkan huruf rahasia ke-{i+1}: ")        # Menginput huruf rahasia sebanyak i

pesanasli=input("Masukkan pesan yang ingin diubah: ")       
pesan="  "              # Membuat pesan baru untuk hasil konversi pesan rahasia
for k in range (len(pesanasli)):
    for j in range (len(pesanasli)):
        if pesanasli[j]==hurufasli[k]:      
            pesan[j]+=hurufrahasia[k]       # Menambah huruf rahasia pada pesan kosong
            print(pesan[j])
        else: pesan[j]+=hurufasli[k]        # Menambah huruf asli pada pesan kosong
        
print(pesan)