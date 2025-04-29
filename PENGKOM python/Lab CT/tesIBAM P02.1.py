N = int(input("Masukkan jumlah huruf pada kamus rahasia: "))
ori = ["*" for i in range(N*2+1)]
rep = ["*" for i in range(N*2+1)]
for i in range(N):
  ori[i] = str(input(f"Masukkan huruf biasa ke-{i+1}: "))
  rep[i] = str(input(f"Masukkan huruf rahasia ke-{i+1}: "))
msg = str(input("Masukkan pesan yang ingin diubah: "))
print("Pesan rahasia Nona Sal:")
for i in msg:
  found = False
  count = 0
  for j in ori:
    if i==j:
      print(rep[count],end="")
      found = True
    else:
      print("",end="")
    count+=1
  if found==False:
    print(i,end="")
