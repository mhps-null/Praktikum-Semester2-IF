count=0
total=0

while True:
    angka=(int(input("Masukkan bilangan: ")))
    if angka==-999:
        break
    
    total+=angka
    count+=1
    mean=total/count

    
print(f"banyak angka adalah {count}")
print(f"total angka adalah {total}")
print(f"rata-rata adalah {mean}")