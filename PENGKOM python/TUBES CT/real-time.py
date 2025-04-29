from datetime import datetime

# Menampilkan waktu real-time
current_time = datetime.now()
print("Waktu sekarang:", current_time)

# Menampilkan waktu real-time
current_time = datetime.now()
# Format waktu agar lebih rapi
formatted_time = current_time.strftime("%Y-%m-%d %H:%M:%S")
print("Waktu dalam format rapi:", formatted_time)
