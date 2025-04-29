import tkinter as tk
from tkinter import *
from datetime import datetime

# ------------------------------------ KAMUS ------------------------------------
# suhu : int              -- Suhu yang ditampilkan pada layar
# mode : str              -- Mode operasi AC (Cool, Dry, Fan, Heat)
# timer : int             -- Timer dalam satuan menit
# kecepatan : int         -- Kecepatan kipas (1, 2, 3, Auto)
# is_on : bool            -- Status AC, ON atau OFF
# ---------------------------------- ALGORITMA ----------------------------------

# Konfigurasi jendela utama
lebar = 300
tinggi = 650

window = tk.Tk()
lebarlayar = window.winfo_screenwidth()
tinggilayar = window.winfo_screenheight()

x = int((lebarlayar / 2) - (lebar / 2))
y = int((tinggilayar / 2) - (tinggi / 2) - 30)

window.geometry(f"{lebar}x{tinggi}+{x}+{y}")
window.resizable(0, 0)
window.title("Remote Air Conditioner")

# ---------- VARIABEL GLOBAL ----------
suhu = 25
mode = "Dry"
kecepatan = 1
timer = 0
is_on = False

# ---------- UPDATE DISPLAY ----------
def update_layar():
    labelmode.config(text=f"Mode : {mode}")
    labelsuhu.config(text=f"{suhu}°C")
    labeltimer.config(text=f"Timer : {timer:02}:00")
    simbolspeed.config(text="🌀" * kecepatan)

def toggle_power():
    global is_on
    is_on = not is_on
    if is_on:
        labelmode.config(text="Mode : Cool")
        labelsuhu.config(text="25°C")
    else:
        labelmode.config(text="")
        labelsuhu.config(text="OFF")
    update_layar()

def ubah_suhu(delta):
    global suhu
    if is_on and 16 <= suhu + delta <= 30:
        suhu += delta
        update_layar()

def ubah_mode():
    global mode
    modes = ["Cool", "Dry", "Fan", "Heat"]
    mode = modes[(modes.index(mode) + 1) % len(modes)]
    update_layar()

def ubah_kecepatan():
    global kecepatan
    kecepatan = (kecepatan % 3) + 1  # Loop antara 1-3
    update_layar()

def set_timer():
    global timer
    timer = (timer + 30) % 180  # Timer maks 3 jam
    update_layar()

def cancel_timer():
    global timer
    timer = 0
    update_layar()

# ---------- LAYAR REMOTE AC ----------
# Layar AC
layar = tk.Frame(window, bg="white", width=260, height=240, highlightbackground="black", highlightthickness=2)
layar.place(x=20, y=10)

layer2 = tk.Frame(window, bg="white", width=195, height=192, highlightbackground="black", highlightthickness=2)
layer2.place(x=85, y=10)

labelsuhu = Label(layer2, text=f"{suhu}°C", font=("Arial", 40), background="white")
labelsuhu.place(x=47.5-10, y=48, width=115+20, height=96)

labelmode = Label(layer2, text=f"Mode : {mode}", font=("Arial", 22), background="white")
labelmode.place(x=0, y=139, width=190, height=48)

labeltimer = Label(layer2, text="Timer : 00:00", font=("Arial", 15), background="white")
labeltimer.place(x=5+2.5, y=0, width=150, height=48)

simbolspeed = Label(layer2, text="🌀", bg="white", font=("Helvetica", 18))
simbolspeed.place(x=5, y=180, width=60, height=55)

# ---------- TOMBOL UTAMA BAGIAN TENGAH ----------
Button(window, text="ON/OFF", bg="firebrick2", command=toggle_power).place(x=120, y=270, width=60, height=60)
Button(window, text="MODE", command=ubah_mode).place(x=125, y=350, width=50, height=50)
Button(window, text="SPEED", command=ubah_kecepatan).place(x=210, y=275, width=50, height=50)
Button(window, text="+", command=lambda: ubah_suhu(1)).place(x=217.5, y=350, width=35, height=62.5)
Button(window, text="-", command=lambda: ubah_suhu(-1)).place(x=217.5, y=412.5, width=35, height=62.5)
Button(window, text="TIMER", command=set_timer).place(x=125, y=515, width=50, height=30)
Button(window, text="CANCEL", command=cancel_timer).place(x=40, y=570, width=50, height=30)

# ---------- INISIALISASI ----------
update_layar()

# Menampilkan jendela
window.mainloop()
