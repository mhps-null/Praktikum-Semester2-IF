R1=int(input("Masukkan nilai Resistor 1 "))
R2=int(input("Masukkan nilai Resistor 2 "))
R3=int(input("Masukkan nilai Resistor 3 "))

Rtotal=((1/R1)+(1/R2)+(1/R3))
Rakhir=float(1/Rtotal)

print(str(Rakhir) + " ohm")