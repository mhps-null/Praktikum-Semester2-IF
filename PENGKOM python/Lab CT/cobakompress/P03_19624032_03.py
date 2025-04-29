# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 21/11/2024
# Deskripsi : Mencari tahu pemenang sesuai aturan soal

# Program mesin bekerja
# Spesifikasi : mencari pemenang

# Kamus
# 

def hitungskor(kartu):
    total=0
    for i in kartu:
        total+=i
    return total

def cek_pemenang(skor,target):
    return skor>=target

def kartu(target, kartudeb, kartusal):
    skordeb=hitungskor(kartudeb)
    skorsal=hitungskor(kartusal)
    gantian=0
    aksi=[]

    while True:
        if gantian%2==0:
            playersekarang= "Nona Deb"
            kartusekarang=kartudeb
            kartumusuh=kartusal
            skorsekarang=skordeb
        else:
            playersekarang= "Nona Sal"
            kartusekarang=kartusal
            kartumusuh=kartudeb
            skorsekarang=skorsal
        aksi=("Tambah", 0)
        for i in range(len(kartusekarang)):
            if skorsekarang+skorsekarang[i]>=target:
                aksi=("Tambah", i)
                break
        tukeranketemu=False
        for i in range(len(kartusekarang)):
            if kartumusuh[i]>kartusekarang[i]:
                aksi=("Tukar", i)
                tukeranketemu=True
                break
# Process
        if aksi[0]=="tambah":
            skorsekarang+=kartusekarang[aksi[1]]
