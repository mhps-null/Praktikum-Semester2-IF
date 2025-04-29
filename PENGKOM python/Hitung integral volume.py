import sympy as sp

def volume_benda():
    print("=== Program Penghitung Volume Benda ===")
    # Input fungsi
    x = sp.symbols('x')
    fungsi = input("Masukkan fungsi batas (dalam x): ")
    f = sp.sympify(fungsi)
    
    # Input batas integral
    batas_a = float(input("Masukkan batas bawah (a): "))
    batas_b = float(input("Masukkan batas atas (b): "))
    
    # Pilih metode
    print("Pilih metode perhitungan volume:")
    print("1. Metode Cakram")
    print("2. Metode Cincin")
    print("3. Metode Kulit Tabung")
    metode = int(input("Masukkan pilihan (1/2/3): "))
    
    # Hitung volume berdasarkan metode
    if metode == 1:
        # Metode Cakram
        print("\nMenggunakan Metode Cakram...")
        integrand = sp.pi * f**2
        volume = sp.integrate(integrand, (x, batas_a, batas_b))
    elif metode == 2:
        # Metode Cincin
        print("\nMenggunakan Metode Cincin...")
        inner_radius = float(input("Masukkan radius dalam (fungsi lebih kecil, dalam x): "))
        outer_radius = float(input("Masukkan radius luar (fungsi lebih besar, dalam x): "))
        r_in = sp.sympify(inner_radius)
        r_out = sp.sympify(outer_radius)
        integrand = sp.pi * (r_out**2 - r_in**2)
        volume = sp.integrate(integrand, (x, batas_a, batas_b))
    elif metode == 3:
        # Metode Kulit Tabung
        print("\nMenggunakan Metode Kulit Tabung...")
        integrand = 2 * sp.pi * x * f
        volume = sp.integrate(integrand, (x, batas_a, batas_b))
    else:
        print("Metode tidak valid.")
        return
    
    # Tampilkan hasil
    print(f"\nVolume benda: {volume.evalf()} satuan kubik")

# Panggil fungsi utama
if __name__ == "__main__":
    volume_benda()
