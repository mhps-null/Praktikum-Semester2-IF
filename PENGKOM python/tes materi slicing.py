# b = "Hello, World!"
# print(b[:5]) = Hello
"""
Di ITB, ada mata kuliah bernama Machine Learning yang berlangsung dari pukul 09:40 hingga 12:20. 
Anda diminta untuk membuat sebuah fungsi yang dapat menentukan status dari mata kuliah tersebut
 berdasarkan waktu saat ini.
"""

pukul = (input("Masukkan pukul : "))
jam = int(pukul[:2])
menit = int(pukul [3:])

if jam>=9 and menit>=40:
    print("berjalan")
if jam<=12 and menit<20:
    print("berjalan")
if jam>=12 and menit>=20:
    print("berakhir")
if jam <=9 and menit<40:
    print("belum dimulai")