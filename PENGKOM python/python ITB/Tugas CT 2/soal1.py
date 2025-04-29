T=[4, 1, 3, 4, 5, 6, 8, 9, 12, 30, -1, 0, 4, -1, 3, 10, 14, 6, 7, 0]
angka=int (input("Masukkan X: "))
for i in range (len(T)):
    T[i]*=angka
print(T)