N=(input("Masukkan banyak panjang array T: "))

T=[0 for i in range (N)]
X=input("Masukkan hal yang kamu cari: ")
Ketemu=False

for i in range (N):
    T[i]=input(f"Masukkan hal ke-{i+1} ")

if Ketemu==False:
    for i in range (N-1,-1,-1):
        if T[i]==X:
            Ketemu=True
            print(f"Hal yang sama ditemukan di indeks ke-{N-(i+1)} dari arah kanan")
    print("Tidak ditemukan")
        