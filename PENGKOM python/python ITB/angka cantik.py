X=int(input("Masukkan X: "))
n=1

if not (X%2 == 0 and X%5 == 0):
    while True:
        if str(n)==str(n)[0]*len(str(n)):
            if n%X==0:
                break
        n+=1
print(n)