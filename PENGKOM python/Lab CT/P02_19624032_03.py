# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 31/10/2024
# Deskripsi : pesan rahasia

pemain=int(input("Banyak pemain: "))        
tiappemain=[1]*100          
array=[1,2,3]           # Pattern kue 1,2,3
jumlahpenunjukkan=int(input("Jumlah penunjukkan: "))

for i in range (0,3):
    tiappemain[i]=tiappemain[i]*array[i]        # Mengalikan tiap isi array(orang) dengan jumlah kue

for j in range (jumlahpenunjukkan):
    tertunjuk=(int(input("Orang yang ditunjuk: ")))     # Deklarasi orang yang ditunjuk
print(tiappemain)