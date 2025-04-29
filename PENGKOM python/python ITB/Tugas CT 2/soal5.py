vektor_V=[0 for i in range (5)]
vektor_U=[0 for i in range (5)]

for i in range (5):
    vektor_V[i]=int(input(f"Masukkan vektor V ke-{i+1} "))
    vektor_U[i]=int(input(f"Masukkan vektor U ke-{i+1} "))

for i in range(5):
    vektor_V[i]+=vektor_U[i]
    
print(vektor_V)