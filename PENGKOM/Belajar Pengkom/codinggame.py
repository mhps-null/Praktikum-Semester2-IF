import sys
import math

n = int(input())
arrPoin = [0] * n
arrKata = [0] * n

# Input kata-kata
for i in range(n):
    arrKata[i] = input()

letters = input()

# Skor huruf berdasarkan aturan Scrabble
skorHuruf = {
    'q': 10, 'z': 10,
    'x': 8,
    'k': 5,
    'f': 4, 'h': 4, 'v': 4, 'w': 4, 'y': 4,
    'b': 3, 'c': 3, 'm': 3, 'p': 3,
    'd': 2, 'g': 2
}

# Hitung skor setiap kata
for i in range(n):
    poin = 0  # Reset poin setiap kata
    kata = arrKata[i]
    
    # Pastikan semua huruf dalam kata ada di daftar huruf yang diberikan
    if all(huruf in letters for huruf in kata):
        for huruf in kata:
            poin += skorHuruf.get(huruf, 1)  # Default skor 1 jika tidak ada di dictionary
    
    arrPoin[i] = poin  # Simpan skor untuk kata ini

# Cari kata dengan skor tertinggi
maks = max(arrPoin)
for i in range(n):
    if arrPoin[i] == maks:
        print(arrKata[i])
        break  # Keluar setelah menemukan kata pertama dengan skor maksimal
