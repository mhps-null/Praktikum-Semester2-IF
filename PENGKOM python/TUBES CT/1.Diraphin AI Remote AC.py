# Program: Remote Air Conditioner GUI
# Spesifikasi: Program ini membuat antarmuka pengguna untuk remote AC dengan berbagai tombol dan layar untuk mengontrol
#              fitur-fitur selayaknya remote AC sungguhan seperti suhu, mode, kecepatan kipas, timer, sleep, dll.

import tkinter as tk
from tkinter import *
from datetime import datetime

# ------------------------------------ KAMUS ------------------------------------
# lebar : int          -- Lebar jendela utama
# tinggi : int         -- Tinggi jendela utama
# lebarlayar : int     -- Lebar layar monitor
# tinggilayar : int    -- Tinggi layar monitor
# x : int              -- Posisi horizontal jendela utama
# y : int              -- Posisi vertikal jendela utama
# formatted_time : str -- Waktu saat ini dalam format yang rapi

# ---------------------------------- ALGORITMA ----------------------------------
# 1. Inisialisasi jendela utama.
# 2. Tambahkan layar untuk menampilkan informasi suhu, mode, waktu, dan simbol-simbol AC.
# 3. Tambahkan tombol-tombol untuk mengontrol fitur seperti ON/OFF, mode, kecepatan, dan timer.
# 4. Tampilkan jendela utama antarmuka pengguna.

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
suhu=int(input("Masukkan suhu awal ruangan: "))
mode = "Auto"
kecepatan = 1
timer = 00
nyalatimer = True
nyala = True
heat = False
cold = False
swing= False
sleep=False
nyalajam=True

if suhu>30:
     suhu=16
     heat=True
elif suhu<10:
     suhu=18
     cold=True

# ---------- LAYAR REMOTE AC ----------

# Membuat layar dengan garis tepi
layar = tk.Frame(window, bg="white", width=260, height=240, highlightbackground="black", highlightthickness=2)
layar.place(x=20, y=10)

# Layer dalam layar
layer1 = tk.Frame(window, bg="white", width=195, height=240, highlightbackground="black", highlightthickness=2)
layer1.place(x=85, y=10)

layer2 = tk.Frame(window, bg="white", width=195, height=192, highlightbackground="black", highlightthickness=2)
layer2.place(x=85, y=10)

# ---------- LABEL PADA LAYAR ----------

# Label untuk suhu
labelsuhu = Label(layer2, text=f"{suhu}°C", font=("Arial", 40), background="white")
labelsuhu.place(x=47.5-10, y=48, width=115+20, height=96)

# Label untuk mode
labelmode = Label(layer2, text=f"Mode : {mode}", font=("Arial", 22), background="white")
labelmode.place(x=0, y=139, width=190, height=48)

# Menampilkan waktu real-time
current_time = datetime.now()
formatted_time = current_time.strftime("%Y-%m-%d | %H:%M:%S")

labeljam = Label(layer1, text=f"{formatted_time}", font=("Arial", 13), background="white")
labeljam.place(x=0, y=190, width=190, height=45.5)

# Label untuk timer
labeltimer = Label(layer2, text=f"Timer : {timer}:00", font=("Arial", 15), background="white")
labeltimer.place(x=5+2.5, y=0, width=150, height=48)

# Simbol tambahan di layar
simbolswing=Label(layar,text="",bg="white",font=("Helvetica", 18))
simbolswing.place(x=17,y=0,width=60, height=60)

simbolhumidity = Label(layar, text="", bg="white", font=("Helvetica", 18))
simbolhumidity.place(x=1.25, y=60, width=60, height=60)

simbolheat = Label(layar, text="", bg="white", font=("Helvetica", 18))
simbolheat.place(x=1.25, y=120, width=60, height=60)

simbolspeed = Label(layar, text="🌀", bg="white", font=("Helvetica", 11))
simbolspeed.place(x=1.25, y=180, width=60, height=55)

simbolsleep = Label(layer2, text="", bg="white", font=("Helvetica", 18))
simbolsleep.place(x=155+2.5, y=0, width=30, height=42)

# Def

def onoff():
    global nyala
    nyala = not nyala
    if nyala==False:
        labelsuhu.place_forget()
        labelmode.place_forget()
        labeltimer.place_forget()
        simbolswing.place_forget()
        simbolhumidity.place_forget()
        simbolheat.place_forget()
        simbolspeed.place_forget()
        simbolsleep.place_forget()
        labeljam.place_forget()
    else:
        labelsuhu.place(x=47.5-10, y=48, width=115+20, height=96)
        labelmode.place(x=0, y=139, width=190, height=48)
        labeltimer.place(x=5+2.5, y=0, width=150, height=48)
        simbolswing.place(x=17, y=0, width=60, height=60)
        simbolhumidity.place(x=1.25, y=60, width=60, height=60)
        simbolheat.place(x=1.25, y=120, width=60, height=60)
        simbolspeed.place(x=1.25, y=180, width=60, height=55)
        simbolsleep.place(x=155+2.5, y=0, width=30, height=42)
        labeljam.place(x=0, y=190, width=190, height=45.5)

# ---------- UPDATE DISPLAY ----------
if heat==True:
    simbolheat.config(text="☀")  
    simbolhumidity.config(text="")
elif cold==True:
     simbolhumidity.config(text="💧")
     simbolheat.config(text="") 

def updatelayar():
    global mode,suhu,timer,kecepatan
    labelmode.config(text=f"Mode : {mode}")
    labelsuhu.config(text=f"{suhu}°C")
    labeltimer.config(text=f"Timer : {timer}:00")
    simbolspeed.config(text="🌀" * kecepatan)
    if sleep==True:
        simbolsleep.config(text="💤")
    else: simbolsleep.config(text="")
    if swing==True:
         simbolswing.config(text="💨↕️")
    else: simbolswing.config(text="")
    if nyalatimer==False:
         labeltimer.config(text="")
    if nyalajam==False:
         labeljam.place_forget()
    else: labeljam.place(x=0, y=190, width=190, height=45.5)
         

def ubahsuhu(delta):
    global suhu
    if nyala==True and 16 <= suhu + delta <= 30:
        suhu += delta
        updatelayar()

def ubahmode():
    global mode,kecepatan
    modes = ["Auto", "Cool", "Dry", "Fan", "Heat"]
    mode = modes[(modes.index(mode) + 1) % len(modes)]
    updatelayar()

def ubahkecepatan(kecepatanbaru=None):
    global kecepatan
    if kecepatanbaru=="Turbo":
            kecepatan=3
    elif kecepatanbaru=="Quiet":
            kecepatan=0
    elif 0<=kecepatan<=3:
        if kecepatan==3:
            kecepatan=1
        else:
            kecepatan+=1
    updatelayar()

def ubahsleep():
     global sleep
     sleep= not sleep
     updatelayar()

def ubahswing():
     global swing
     swing=not swing
     updatelayar()

def ubahnyalatimer(nyalagak):
     global nyalatimer
     if nyalagak=="ON":
          nyalatimer=True
     else: nyalatimer=False
     updatelayar()

def ubahtimer(waktu):
    global timer
    if timer>=0:
        timer+=waktu
    if timer==-1:
         timer=0
    updatelayar()

def ubahnyalajam():
     global nyalajam
     nyalajam= not nyalajam
     updatelayar()

# ---------- TOMBOL UTAMA BAGIAN TENGAH ----------
Button(text="ON/OFF",command=onoff, background="firebrick2",activebackground="firebrick2").place(x=120, y=270, width=60, height=60)
Button(text="SWING",command=lambda: ubahswing()).place(x=40, y=275, width=50, height=50)
Button(text="SPEED",command=lambda:ubahkecepatan()).place(x=210, y=275, width=50, height=50)
Button(text="MODE",command=lambda:ubahmode()).place(x=125, y=350, width=50, height=50)
Button(text="TURBO",command=lambda: ubahkecepatan("Turbo")).place(x=40, y=350, width=50, height=50)
Button(text="QUIET",command=lambda: ubahkecepatan("Quiet")).place(x=40, y=425, width=50, height=50)
Button(text="SLEEP",command=lambda: ubahsleep()).place(x=125, y=425, width=50, height=50)
Button(text="+",command=lambda:ubahsuhu(1)).place(x=217.5, y=350, width=35, height=62.5)
Button(text="-",command=lambda:ubahsuhu(-1)).place(x=217.5, y=412.5, width=35, height=62.5)

# ---------- TOMBOL TIMER BAGIAN BAWAH ----------
tk.Frame(window, width=245, height=115, highlightbackground="black", highlightthickness=0.5).place(x=27.5, y=500)

Label(text="Ini Merek", font=("Helvetica", 14, "bold")).place(x=110, y=615, width=90, height=45)
Label(text="T I M E R", font=("Arial", 12)).place(x=117.5, y=515, width=65, height=30)

Button(text="ON",command=lambda: ubahnyalatimer("ON")).place(x=40, y=515, width=50, height=30)
Button(text="+",command=lambda: ubahtimer(1)).place(x=40, y=570, width=50, height=30)
Button(text="OFF",command=lambda:ubahnyalatimer("OFF")).place(x=210, y=515, width=50, height=30)
Button(text="-",command=lambda: ubahtimer(-1)).place(x=210, y=570, width=50, height=30)
Button(text="CLOCK",command=lambda:ubahnyalajam()).place(x=125, y=570, width=50, height=30)

# Menampilkan jendela
window.mainloop()