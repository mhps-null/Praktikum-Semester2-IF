def tulis_menu(pil1,pil2,pil3):
    print("Menu: ")
    print(f"1. {pil1}")
    print(f"2. {pil2}")
    print(f"3. {pil3}")
    print("Masukkan pilihan: ")
    return pil1,pil2,pil3

tulis_menu("Burger", "Ayam", "Kecap")
pilihan_makanan=int(input("No: "))

tulis_menu("00", "11", "22")
pilihan_makanan=int(input("No: "))

tulis_menu("33", "44", "55")
pilihan_makanan=int(input("No: "))
