# Program hitung poin
# Spesifikasi: Setiap tahap panjat tebing memiliki batas waktu maksimal 15 menit.
#  • Jumlah poin yang didapatkan adalah 45 dikurangi dengan total waktu dari setiap tahap.
#  • Jika waktu penyelesaian Tuan Leo untuk sebuah tahap kurang dari 5 menit, maka ia mendapatkan
#  tambahan maksimal waktu sebesar 2 menit untuk tahap berikutnya.
#  • Jika Tuan Leo menyelesaikan semua tahap dengan total waktu kurang dari 30 menit, ia mendapatkan
#  bonus poin sebesar 10 poin.
#  • Jika pada salah satu tahap waktu yang dibutuhkan melebihi 15 menit tanpa bonus waktu maksimal,
#  maka Tuan Leo dinyatakan gugur dan tidak mendapatkan poin.

# KAMUS

# Algoritma
tahap1=int(input("Masukkan waktu tahap 1 (menit): "))
tahap2=int(input("Masukkan waktu tahap 2 (menit): "))
tahap3=int(input("Masukkan waktu tahap 3 (menit): "))

totalwaktu=tahap1+tahap2+tahap3
totalpoin=45-totalwaktu
bataswaktu=15

if tahap1<5 or tahap2<5 or tahap3<5:
    bataswaktu+=2

if totalwaktu<30:
    totalpoin+=10

if tahap1>bataswaktu or tahap2>bataswaktu or tahap3>bataswaktu:
    totalpoin=0

print (f"Total waktu yang dihabiskan adalah {totalwaktu} menit Poin yang didapatkan adalah {totalpoin}")