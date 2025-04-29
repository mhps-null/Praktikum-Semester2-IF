import tkinter as tk
from tkinter import *

import datetime as dt
from datetime import datetime

# Jendela Utama
lebar=300       
tinggi=650

window= tk.Tk()
lebarlayar=window.winfo_screenwidth()
tinggilayar=window.winfo_screenheight()

x=int((lebarlayar/2) - (lebar/2))
y=int((tinggilayar/2) - (tinggi/2)-30)

window.geometry(f"{lebar}x{tinggi}+{x}+{y}")
window.resizable(0,0)
window.title("Remote Air Conditioner")

# ---------- LAYAR REMOTE AC ----------

# Membuat layar dengan garis tepi
layar = tk.Frame(window, bg="white", width=260, height=240, highlightbackground="black", highlightthickness=2)
layar.place(x=20,y=10)

# Membuat layer 1 pada layar
layer1 = tk.Frame(window, bg="white", width=195, height=240, highlightbackground="black", highlightthickness=2)
layer1.place(x=85,y=10)

# Membuat layer 2 pada layar
layer2 = tk.Frame(window, bg="white", width=195, height=192, highlightbackground="black", highlightthickness=2)
layer2.place(x=85,y=10)

# Label Suhu
labelsuhu=Label(layer2,text="25°C", font=("Arial", 35), background="white")
labelsuhu.place(x=97.5-((97.5+10)/2),y=48, width=97.5+10, height=96)

# Label Mode
labelmode=Label(layer2,text="Mode : Dry", font=("Arial", 22), background="white")
labelmode.place(x=0,y=139, width=190, height=48)

# Menampilkan waktu real-time
current_time = datetime.now()
# Format waktu agar lebih rapi
formatted_time = current_time.strftime("%Y-%m-%d | %H:%M:%S")

# Label Jam
labeljam=Label(layer1,text=f"{formatted_time}", font=("Arial", 13), background="white")
labeljam.place(x=0,y=190, width=190, height=45.5)

# Label Timer
labeltimer=Label(layer2,text="Timer : 01:30:00", font=("Arial", 15), background="white")
labeltimer.place(x=5,y=0, width=150, height=48)

# Symbol Swing
simbolswing=Label(layar,text="💨↕️",bg="white",font=("Helvetica", 18))
simbolswing.place(x=17,y=0,width=60, height=60)

# Symbol Kelembapan
simbolhumidity=Label(layar,text="💧",bg="white",font=("Helvetica", 18))
simbolhumidity.place(x=1.25,y=60,width=60, height=60)

# Symbol Heat
simbolheat=Label(layar,text="☀",bg="white",font=("Helvetica", 18))
simbolheat.place(x=1.25,y=120,width=60, height=60)

# Symbol Speed
simbolspeed=Label(layar,text="🌀🌀🌀",bg="white",font=("Helvetica", 11))
simbolspeed.place(x=1.25,y=180,width=60, height=55)

# Symbol Sleep
simbolsleep=Label(layer2,text="💤",bg="white",font=("Helvetica", 18), background="white")
simbolsleep.place(x=155,y=0, width=30, height=42)

# ---------- TOMBOL UTAMA BAGIAN TENGAH ----------

# Tombol ON/OFF
tombolonoff=Button(text="ON/OFF",background="firebrick2",activebackground="firebrick2")
tombolonoff.place(x=120,y=270, width=60, height=60,)

# Tombol Swing
tombolswing=Button(text="SWING")
tombolswing.place(x=40,y=275, width=50, height=50,)

# Tombol Speed
tombolspeed=Button(text="SPEED")
tombolspeed.place(x=210,y=275, width=50, height=50,)

# Tombol Mode   
tombolmode=Button(text="MODE")
tombolmode.place(x=125,y=350, width=50, height=50)

# Tombol Turbo
tombolturbo=Button(text="TURBO")
tombolturbo.place(x=40,y=350, width=50, height=50)

# Tombol Quiet
tombolquiet=Button(text="QUIET")
tombolquiet.place(x=40,y=425, width=50, height=50,)

# Tombol Sleep
tombolsleep=Button(text="SLEEP")
tombolsleep.place(x=125,y=425, width=50, height=50,)

# Tombol + suhu
tombolnaik=Button(text="+")
tombolnaik.place(x=217.5,y=350, width=35, height=62.5)

# Tombol - suhu
tombolturun=Button(text="-")
tombolturun.place(x=217.5,y=412.5, width=35, height=62.5)

# ---------- TOMBOL TIMER BAGIAN BAWAH ----------

# Membuat garis tepi untuk timer
garistepi = tk.Frame(window, width=245, height=115, highlightbackground="black", highlightthickness=0.5)
garistepi.place(x=27.5,y=500)

# Label watermark hasil perjuangan
labelmerek=Label(text="Ini Merek",font=("Helvetica", 14, "bold"))
labelmerek.place(x=110,y=615,width=90, height=45)

# Label timer
labeltimer=Label(text="T I M E R", font=("Arial", 12))
labeltimer.place(x=117.5,y=515, width=65, height=30)

# Tombol on timer
tombolontimer=Button(text="ON")
tombolontimer.place(x=40,y=515, width=50, height=30)

# Tombol cancel timer 1
tombolcanceltimer1=Button(text="CANCEL")
tombolcanceltimer1.place(x=40,y=570, width=50, height=30)

# Tombol off timer
tombolofftimer=Button(text="OFF")
tombolofftimer.place(x=210,y=515, width=50, height=30)

# Tombol cancel timer 2
tombolcanceltimer2=Button(text="CANCEL")
tombolcanceltimer2.place(x=210,y=570, width=50, height=30)

# Tombol clock
tombolclock=Button(text="CLOCK")
tombolclock.place(x=125,y=570, width=50, height=30)

window.mainloop()