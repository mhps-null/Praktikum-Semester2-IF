#Program menghitung poin makan kerupuk
#Spesifikasi: jika ada satu orang tim yang memilih cara makan berbeda dengan yang lainnya

#KAMUS
#Deb : int
#Sal : Int
#Leo : int

#Algoritma
Deb = int(input("Jumlah kerupuk Nona Deb: "))
KecapDeb=str(input("Pakai Kecap? "))
Sal = int(input("Jumlah kerupuk Nona Sal: "))
KecapSal=str(input("Pakai Kecap? "))
Leo = int(input("Jumlah kerupuk Nona Leo: "))
KecapLeo=str(input("Pakai Kecap? "))

if KecapDeb==KecapSal==KecapLeo:
    if Deb>=Sal and Deb>=Leo:
        if Sal>=Leo:
            poin=Deb+Sal
            print(poin) 
        else:
            poin=Leo+Deb
            print(poin) 
    if Sal>Deb and Sal>=Leo:
        if Deb>=Leo:
            poin=Deb+Sal
            print(poin) 
        else:
            poin=Leo+Sal 
            print(poin)   
    if Leo>Deb and Leo>Sal:
        if Deb>=Sal:
            poin=Deb+Leo
            print(poin) 
        else:
            poin=Leo+Sal 
            print(poin) 
else: print(0)