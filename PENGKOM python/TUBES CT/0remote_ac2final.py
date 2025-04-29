
## KAMUS
# suhu_ruang : int               
# speed_output : list didalamnya menggunakan [str]       
# speed : str                     
# x : int                         
# swing : str                     
# mode : str                      
# nyala : bool                    
# kompresor : str                 
# fan_outdoor : str               
# suhu_ruangan_saat_ini : int     


## ALGORITMA
# Inisialisasi variabel awal untuk AC
suhu_ruang = 25    # Suhu ruangan default saat AC dinyalakan           
speed_output = ["Low " , "Mid " , "High"]   # Pilihan kecepatan kipas
speed = speed_output[0]   # Kecepatan kipas default adalah "Low"
x = 0   # Indeks untuk mengatur kecepatan kipas
swing = "On "   # Swing default menyala
mode = "   Cooling   "   # Mode default AC adalah "Cooling"
nyala = True   # Status awal AC (true = hidup)
kompresor = "OFF"
fan_outdoor = "OFF"

# Fungsi untuk mengecek status kompresor dan fan outdoor
def cek_status_kompresor(suhu_ruangan_saat_ini):
    global kompresor, fan_outdoor
    if mode == "    Fan      ":
        kompresor = "OFF"
        fan_outdoor = "OFF"
    elif suhu_ruangan_saat_ini > suhu_ruang:
        kompresor = "ON"
        fan_outdoor = "ON"
    else:
        kompresor = "OFF"
        fan_outdoor = "OFF"

# Fungsi untuk menampilkan status AC
def remote_ac():
    print( f'''
        ======================================
        ||     MODE      |    SPEED: {speed}   ||  
        ||               |------------------||
        || {mode} |                  ||       Status Kompresor   : {kompresor}
        ||               |       {suhu_ruang}°C       ||       Status Fan Outdoor : {fan_outdoor}
        ||               |                  ||  
        ||               |------------------||  
        ||               |    SWING: {swing}    ||    
        ======================================
        |    (ON/OFF)             (MODE)     |
        |                                    |
        |           (-)       (+)            |
        |                                    |
        |    (SPEED)              (SWING)    |
        |                                    |
        |------------------------------------|
        |        *****AC REMOTE*****         |
        --------------------------------------
''')

# Input suhu ruangan saat pertama kali dijalankan
suhu_ruangan_saat_ini = input("Masukkan suhu ruangan saat ini (°C): ")
while not suhu_ruangan_saat_ini.isdigit():  # Memastikan input adalah angka
    print("Mohon masukkan angka yang valid!")
    suhu_ruangan_saat_ini = input("Masukkan suhu ruangan saat ini (°C): ")
suhu_ruangan_saat_ini = int(suhu_ruangan_saat_ini)

# Mengecek status awal kompresor dan fan outdoor
cek_status_kompresor(suhu_ruangan_saat_ini)
# Menampilkan status awal AC saat pertama kali di Run
remote_ac()

# Loop utama untuk program remote AC
while nyala:
# Menu utama untuk memilih tindakan
    ingin_ngapain = input('''
1. Suhu
2. Mode
3. Speed
4. Swing
5. Off AC                        

Masukkan nomor perintah yang ingin dijalankan: ''')
    # Pilihan untuk mengatur suhu ruangan
    if ingin_ngapain == "1":
        tombol_suhu = input("\nApakah kamu ingin menaikkan atau menurunkan suhu (+/-) atau kembali: ")
        if tombol_suhu == '+':   # Menaikkan suhu
            suhu_ruang += 1
            if suhu_ruang == 31:   # Batas maksimum suhu adalah 30°C
                suhu_ruang = 30
        elif tombol_suhu == '-':   # Menurunkan suhu
            suhu_ruang -= 1
            if suhu_ruang == 15:   # Batas minimum suhu adalah 16°C
                suhu_ruang = 16 
        elif tombol_suhu == 'kembali':   # ketik kembali untuk kembali ke menu utama
            suhu_ruang == suhu_ruang
        else :
            print("Ketik input sesuai prompt!")   # meminta input yang sesuai dengan menu/prompt
        cek_status_kompresor(suhu_ruangan_saat_ini)    # Update status kompresor dan fan outdoor secara dinamis
        remote_ac()   # menampilkan status AC setelah perubahan

     # Pilihan untuk mengatur mode AC
    elif ingin_ngapain == "2":
        tombol_mode = input("\nApakah kamu ingin mengubah mode?(yes/no): ")
        if tombol_mode == "yes" :
            print('''
1. Cooling
2. Heating
3. Dehumidifying
4. Fan
''')
            pilih_mode = input("Pilih nomor mode yang kamu inginkan atau kembali: ")
            if pilih_mode == "1" :
                mode = "   Cooling   "   # Mode pendinginan
            elif pilih_mode == "2" :
                mode = "   Heating   "    # Mode pemanasan(jarang digunakan di Indonesia biasanya banyak di gunakan di negara musim dingin)
            elif pilih_mode == "3" :
                mode = "Dehumidifying"    # Mode menyerap kelembapan atau sering disebut mode dry
            elif pilih_mode == "4" :
                mode = "    Fan      "   # Mode kipas
                suhu_ruang = 25    # Suhu tetap diatur ke 25 derajat
            elif pilih_mode == "kembali" :   # ketik kembali untuk kembali ke menu utama
                mode = mode
            else :
                print("Mohon Ketik input sesuai prompt!")   # meminta input yang sesuai dengan menu/prompt
            cek_status_kompresor(suhu_ruangan_saat_ini)    # Update status kompresor dan fan outdoor secara dinamis
            remote_ac()   # menampilkan status AC setelah perubahan

    # Pilihan untuk mengatur kecepatan angin AC
    elif ingin_ngapain == "3":
        tombol_speed = input("Apakah kamu ingin menaikkan atau menurunkan fan(+/-) atau kembali : ")
        if tombol_speed == "+" :   # Menaikkan kecepatan angin
            # menaikkan kecepatan angin sampai maksimal 'high'
            if x >= 0 and x <2 :   
                x += 1
                speed = speed_output[x] 
            elif x >= 2 :
                x = 2
                speed =  speed_output[x]
        elif tombol_speed == "-" :   # Menurunkan kecepatan kipas
            # menurunkan kecepatan angin sampai minimal 'low'
            if x <=2 and x > 0 :     
                x -= 1 
                speed = speed_output[x] 
            elif x <=0 :
                x = 0
                speed = speed_output[x]
        elif tombol_speed == "kembali" :   # ketik kembali untuk kembali ke menu utama
            speed = speed_output[x]
        else :
            print("Mohon ketik input sesuai dengan promptnya!")   # meminta input yang sesuai dengan menu/prompt
        remote_ac()   # menampilkan status AC setelah perubahan
            
    # Pilihan untuk mengatur swing
    elif ingin_ngapain == "4":
        tombol_swing = input("Apakah anda ingin menyalakan atau mematikan swing(on/off) atau kembali: ") 
        if tombol_swing == "on" :   # Menyalakan swing
            swing = "On "   
        elif tombol_swing == "off" :   # Mematikan swing
            swing = "Off" 
        elif tombol_swing == "kembali" :    # ketik kembali untuk kembali ke menu utama
            swing = swing
        else :
            print("Mohon ketik input sesuai dengan promptnya!")  # meminta input yang sesuai dengan menu/prompt
        remote_ac()   # menampilkan status AC setelah perubahan
    
    
    # Pilihan untuk mematikan AC        
    elif ingin_ngapain == "5" :
        print(f'''
        ======================================
        ||               |                  ||  
        ||               |------------------||
        ||               |                  ||
        ||               |                  ||
        ||               |                  ||  
        ||               |------------------||  
        ||               |                  ||    
        ======================================
        |    (ON/OFF)             (MODE)     |
        |                                    |
        |           (-)       (+)            |
        |                                    |
        |    (SPEED)              (SWING)    |
        |                                    |
        |------------------------------------|
        |        *****AC REMOTE*****         |
        --------------------------------------
''')
        nyala = False   # mematikan AC