nPemain = int(input("Banyak pemain: "))
nTunjuk = int(input("Jumlah penunjukan: "))

kue = [(i+1)%3 for i in range(nPemain)]
    
for i in range(nTunjuk):
  a = int(input(f"Orang ke-{i+1} yang ditunjuk: "))
  if kue.__len__()>=a-1+kue[a-1]+1 and kue[a-1+kue[a-1]-1]!=0:
    kue[a-1+kue[a-1]] -= 1
  if a-1-kue[a-1]>=0 and kue[a-1-kue[a-1]]!=0:
    kue[a-1-kue[a-1]] -= 1
  kue[a-1] += 1
  if kue[a-1]>3:
    kue[a-1] = 3

highscore = -1
highperson = -1
highpeople = ["*" for i in range(nPemain)]
for i in range(nPemain):
  if(kue[i]>highscore):
    highpeople = ["*" for i in range(nPemain)]
    highscore = kue[i]
    highpeople[i] = str(i)
  if(kue[i]==highscore):
    highpeople[i] = str(i)
print(f"Orang yang memiliki kue terbanyak adalah orang ", end="")
for i in highpeople:
  if i != "*" :
    print(int(i)+1,end=",")