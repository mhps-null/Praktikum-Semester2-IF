#Program Konversi Mata Uang Peng Kom
#Spesifikasi : Menghitung konversi uang yang lebih banyak

#KAMUS
#Peng : Int
#Kom  : Int

#Algoritma
peng=(int(input("Masukkan banyak uang peng: ")))
kom=(int(input("Masukkan banyak uang kom: ")))

konversipeng=(int(input("Masukkan Konversi Uang Peng: ")))
konversikom=(int(input("Masukkan Konversi Uang Kom: ")))

totalpeng=peng*konversipeng
totalkom=kom*konversikom

if totalpeng>totalkom:
    print("Adik Tuan Leo memilih uang Peng.")
elif totalpeng==totalkom:
    print("Adik Tuan Leo memilih uang Kom atau Peng sama saja. ")
else:
    print("Adik Tuan Leo memilih uang Kom. ")
