# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 17/10/2024
# Deskripsi : Mencari apakah angka yg diinput unik

angka=int(input("Masukkan sebuah bilangan: "))

ribuan=angka//1000
ratusan=(angka-(ribuan*1000))//100
puluhan=((angka-(ribuan*1000)-(ratusan*100))//10)

if puluhan==0:
     puluhan=1

if ratusan==0:
     ratusan=1

if ribuan==0:
     ribuan=1

satuan=(angka-(ribuan*1000)-(ratusan*100)-(puluhan*10))

if not (ribuan==ratusan or ribuan==puluhan or ribuan==satuan or ratusan==puluhan or ratusan==satuan or puluhan==satuan) and not (ribuan+ratusan+puluhan+satuan)%2==0:
        if ribuan>satuan and angka%2==0 and ribuan<ratusan+puluhan:
            print("Bilangan tersebut adalah bilangan Super Unik.")

elif not (ribuan==ratusan or ribuan==puluhan or ribuan==satuan or ratusan==puluhan or ratusan==satuan or puluhan==satuan) and not (ribuan+ratusan+puluhan+satuan)%2==0:
    print("Bilangan tersebut adalah bilangan Unik.")

else:
     print("Bilangan tersebut adalah bilangan Biasa.")
