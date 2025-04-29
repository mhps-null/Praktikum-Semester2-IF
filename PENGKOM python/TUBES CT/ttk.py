import tkinter as tk
from tkinter import ttk

# Membuat jendela utama
root = tk.Tk()
root.title("Contoh ttk")
root.geometry("300x200")

# Membuat label dengan ttk
label = ttk.Label(root, text="Pilih opsi:")
label.pack(pady=10)

# Membuat combobox dengan ttk
combobox = ttk.Combobox(root, values=["Opsi 1", "Opsi 2", "Opsi 3"])
combobox.pack(pady=10)

# Membuat tombol dengan ttk
button = ttk.Button(root, text="Klik Saya", command=lambda: print("Tombol ditekan!"))
button.pack(pady=10)

# Menjalankan aplikasi
root.mainloop()
