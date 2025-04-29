# Input
pesan=input("Masukkan pesan misterius: ")
pesan=list(pesan)

# Process 
def terjemah(pesan): 
    akhir=0
    for _ in range (len(pesan)) :
        if pesan[_]=="A" or pesan[_]=="I" or pesan[_]=="U" or pesan[_]=="E" or pesan[_]=="O":
            akhir+=((ord(pesan[_]))-65)*2
        else: 
            akhir+=((ord(pesan[_]))-65)
    print(akhir)

terjemah(pesan)