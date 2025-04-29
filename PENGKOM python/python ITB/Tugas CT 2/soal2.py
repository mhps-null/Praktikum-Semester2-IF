Nilai_Mahasiswa=[0 for i in range (50)]
Lulus=0

for i in range (len(Nilai_Mahasiswa)):
    Nilai_Mahasiswa[i]=str(input(f"Masukkan nilai mahasiswa ke-{i+1}: "))
for i in range(len(Nilai_Mahasiswa)):
    if Nilai_Mahasiswa[i]==str("A") or Nilai_Mahasiswa[i]==str("B") or Nilai_Mahasiswa[i]==str("C:"):
        Lulus+=1
print(f"Banyak mahasiswa yang lulus adalah {Lulus}")
print(f"Banyak mahasiswa yang tidak lulus adalah {50-Lulus}")