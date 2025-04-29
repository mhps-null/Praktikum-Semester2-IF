def fungsi(x):
    f=(x**2)-(2*x)+5
    return f


# Input
A=int(input("Masukkan A: "))
B=int(input("Masukkan B: "))

# Process
total=0
for i in range (A,B+1):
    total+=(fungsi(i))
    print (f"f({i}) = {fungsi(i)}")

# Output
print(total)