def ganjil(array):
    jumlah=0
    for j in range (len(array)-1,-1,-2):
        jumlah+=array[j]
    return jumlah
def ubahkeint(angka):
    array=[0 for _ in range (len(angka))]
    for i in range (len(angka)):
        array[i]=angka[i]
        array[i]=int(array[i])
    return array
def genap(array):
    jumlah=0
    for j in range (len(array)-2,-1,-2):
        jumlah+=array[j]
    return jumlah


array=str(21)
print(genap(ubahkeint(array)))