# Terdapat 2 gedung yang bisa digunakan untuk melaksanakan kegiatan. Sebagai pengurus fasilitas, Tuan Leo
#  harus menentukan jumlah kegiatan yang dapat dilaksanakan dalam 1 hari serta pembagian kegiatan untuk
#  masing-masing gedung.
#  • Gedung A akan digunakan untuk kegiatan dengan peserta kurang dari N, dengan kapasitas maksimal
#  5 kegiatan.
#  • Gedung B digunakan untuk kegiatan lain, dengan kapasitas maksimal 3 kegiatan.
#  Jika Gedung B sudah penuh, Tuan Leo akan berhenti menerima kegiatan tambahan. Namun, jika Gedung A
#  penuh dan masih ada tempat di Gedung B, maka kegiatan akan dialihkan ke Gedung B.
#  Bantulah Tuan Leo menyelesaikan masalah pembagian kegiatan ini.
N=int(input("Masukkan N: "))
kegiatanA=0
kegiatanB=0

while kegiatanB<=3:
    peserta=int(input("peserta: "))
    if peserta<N and kegiatanA<=5:
        kegiatanA+=1
        if kegiatanA>=5:
            kegiatanB+=1
    elif peserta>=N:
        kegiatanB+=1
    if kegiatanB+kegiatanA>=8:
        break
    if kegiatanB>=3:
        break
print(f"A: {kegiatanA} dan B: {kegiatanB}")