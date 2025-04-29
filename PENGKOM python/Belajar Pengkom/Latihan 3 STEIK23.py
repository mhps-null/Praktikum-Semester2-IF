# Input
berangkat=int(input("Jam keberangkatan: "))
pulang=int(input("Jam kepulangan: "))

# Proses
biaya=0

if 6<=berangkat<=8 or 15<=berangkat<=17:
    moda_berangkat="Bus Universitas"
elif 7<=berangkat<=18:
    moda_berangkat="Bus Kota"
    biaya+=5000
else: 
    moda_berangkat="Travel"
    biaya+=10000

if 6<=pulang<=8 or 15<=pulang<=17:
    moda_pulang="Bus Universitas"
elif 7<=pulang<=18:
    moda_pulang="Bus Kota"
    biaya+=5000
else: 
    moda_pulang="Travel"
    biaya+=10000

# Output
print (f"Mas Hanies berangkat naik {moda_berangkat} dan pulang naik {moda_pulang} dengan biaya {biaya}")