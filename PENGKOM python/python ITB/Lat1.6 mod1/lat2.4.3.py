N=int(input("Masukkan N"))
array=[0 for i in range (N)]

for i in range (N):
    array[N-i-1]=int(input())
print(array)
