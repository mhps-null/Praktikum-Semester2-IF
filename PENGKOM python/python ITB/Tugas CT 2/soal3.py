N=int(input("Masukkan panjang array (N): "))
T=[0 for i in range (N)]
Tmaks=T[0]

for i in range (len(T)):
    T[i]=float(input(f"Masukkan list ke {i+1}: "))

for i in range (1,len(T)):
    if Tmaks>T[i]:
        Tmaks=T[i]
print(f"{Tmaks} adalah angka terkecil")