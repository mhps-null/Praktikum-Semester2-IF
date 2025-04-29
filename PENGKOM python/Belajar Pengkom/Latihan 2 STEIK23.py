CPU= int(input("Masukkan level kemampuan CPU "))
GPU= int(input("Masukkan level kemampuan GPU "))
HDD= int(input("Masukkan level kemampuan HDD "))

if CPU<2 or GPU<2 or HDD<2:
    kelompok=1
elif CPU<5 or GPU<5:
    kelompok=2
elif CPU<=7 and GPU<=7 and HDD<=7:
    kelompok=3
elif CPU<=7 or GPU<=7 or HDD<=7:
    kelompok=4
elif CPU>7 and GPU>7 and HDD>7:
    kelompok=5

print(f"Kelompok {kelompok}")