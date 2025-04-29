#include <stdio.h>

int aura(unsigned int x)
{
// Asumsi unsigned int adalah 32-bit
  // Lipat 32 bit menjadi 16 bit
  x = x ^ (x >> 16); // Ops: ^, >> (2 ops)
  // Lipat 16 bit menjadi 8 bit
  x = x ^ (x >> 8);  // Ops: ^, >> (2 ops)
  // Lipat 8 bit menjadi 4 bit
  x = x ^ (x >> 4);  // Ops: ^, >> (2 ops)
  // Lipat 4 bit menjadi 2 bit
  x = x ^ (x >> 2);  // Ops: ^, >> (2 ops)
  // Lipat 2 bit menjadi 1 bit
  x = x ^ (x >> 1);  // Ops: ^, >> (2 ops)

  // Bit paling kanan (LSB) sekarang menyimpan paritas
  // (1 jika jumlah bit '1' asli ganjil, 0 jika genap)
  // Ambil LSB menggunakan bitwise AND dengan 1
  return x & 1;      // Ops: & (1 op)
}

int main(){

    printf("%d\n",aura(0b01));

    return 0;
}