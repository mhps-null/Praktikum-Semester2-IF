kar1=input("Masukkan karakter-1: ")
kar2=input("Masukkan karakter-2: ")
n=int(input("Masukkan nilai n: "))
i=0

def func(a,b,num):
    if num==0:
        return a
    elif num==1:
        return a+b
    else:
        return func(a,b,num-1)+func(b,a,num-1)

print(func(kar1,kar2,n))