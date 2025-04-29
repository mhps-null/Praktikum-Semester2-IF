# Input
N=int(input("Masukkan N: "))

arr=[[0 for _ in range (N)]for _ in range (N)]
for i in range (N):
    for j in range (N):
        if i==0 or j==0:
            arr[i][j]=1
        else:
            arr[i][j]=arr[i-1][j]+arr[i][j-1]

for i in range(N):
    for j in range(N):
        print(arr[i][j], end=" ")
    print()