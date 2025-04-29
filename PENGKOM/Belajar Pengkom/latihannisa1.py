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