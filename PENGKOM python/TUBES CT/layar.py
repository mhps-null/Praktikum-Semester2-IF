import tkinter as tk
from tkinter import *

# Jendela Utama
lebar=300
tinggi=600

window= tk.Tk()
lebarlayar=window.winfo_screenwidth()
tinggilayar=window.winfo_screenheight()

x=int((lebarlayar/2) - (lebar/2))
y=int((tinggilayar/2) - (tinggi/2)-30)

window.geometry(f"{lebar}x{tinggi}+{x}+{y}")
window.resizable(0,0)
window.title("Remote Air Conditioner")

# Membuat layar dengan garis tepi
layar = tk.Frame(window, bg="white", width=300, height=150, highlightbackground="black", highlightthickness=2)
layar.pack(pady=20)

window.mainloop()