# Input
N=int(input("Masukkan N: "))

# Proses
bb=[0 for i in range(1,N+1)]
for i in range (1,N+1):
    bb=(input(f"Masukkan berat petinju ke-{i} "))
    if (bb[-2]+bb[-1])=="kg":
        bb=(int(bb[0:3]))*2.205
        bb=int(bb)
        if bb>=200:
            print(f"petinju ke-{i} masuk ke dalam kelas Heavyweight")
        elif 154<bb<200:
            print(f"petinju ke-{i} masuk ke dalam kelas Middleweight")
        else: print(f"petinju ke-{i} masuk ke dalam kelas Lightweight")
    elif (bb[-2]+bb[-1])=="lb":
        bb=int(bb[0:3])
        if bb>=200:
            print(f"petinju ke-{i} masuk ke dalam kelas Heavyweight")
        elif 154<bb<200:
            print(f"petinju ke-{i} masuk ke dalam kelas Middleweight")
        else: print(f"petinju ke-{i} masuk ke dalam kelas Lightweight")