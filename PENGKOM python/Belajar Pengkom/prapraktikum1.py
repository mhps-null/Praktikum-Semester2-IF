# Input
a=int(input("Masukkan nilai a: "))
b=int(input("Masukkan nilai b: "))
c=int(input("Masukkan nilai c: "))

# Process
def disk(a,b,c):
    d=float((b**2)-(4*(a*c))) # Ini Fungsi  
    return d
def akhir(d): # Ini Prosedur
    print(f"Nilai diskriminan: {d}")
    if d>0:
        print("Persamaan kuadrat memiliki akar berbeda")
    elif d==0:
        print("Persamaan kuadrat memiliki akar kembar")
    else: print("Persamaan kuadrat tidak memiliki akar real")

disk(a,b,c)
d=float((b**2)-(4*(a*c)))
akhir(d)