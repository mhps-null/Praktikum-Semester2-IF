"""waktu 2 jam, 1 jam sudah berlalu. 
Total soal isian singkat ada 14, essay 2. 1 soal isian singkat 10 menit, 1 soal essay 20 menit. 
tentukan dari menginput soal yang sudah dikerjakan, apakah bisa selesai tepat waktu?"""

isian = int(input("Banyak soal isian yang sudah dikerjakan : "))
essay = int(input("Banyak soal essay yang sudah dikerjakan : "))

#sisa 60 menit, 10x+20y<60
if isian>14 or essay>2:
    print("banyak soal yang dimasukkan lebih dari soal yang ada, alias error")
elif isian<14 and essay<2 and (10*(14-isian))+(20*(2-essay))<=60:
    print("Akan sempat terisi semua") 
else :
    print("Tidak akan sempat terisi semua")