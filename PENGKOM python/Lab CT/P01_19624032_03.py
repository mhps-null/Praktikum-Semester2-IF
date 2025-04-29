# NIM/Nama : 19624032/Muhammad Haris Putra Sulastianto
# Tanggal : 17/10/2024
# Deskripsi : Mencari apakah bisa membuat barang dari bahan yang disediakan

demand_bunga=(int(input("Masukkan jumlah pesanan gantungan kunci bunga: ")))
demand_ayam=(int(input("Masukkan jumlah pesanan gantungan kunci ayam: ")))
demand_kupukupu=(int(input("Masukkan jumlah pesanan gantungan kunci kupu-kupu: ")))

bahan_clay_merah=(int(input("Masukkan jumlah clay merah:")))
bahan_clay_biru=(int(input("Masukkan jumlah clay biru:")))
bahan_clay_ungu=(int(input("Masukkan jumlah clay ungu:")))

if bahan_clay_merah>=(2*demand_bunga) and bahan_clay_biru>=(1*demand_bunga):
    bahan_clay_merah-=2*demand_bunga
    bahan_clay_biru-=1*demand_bunga
    if bahan_clay_merah>=(1*demand_ayam) and bahan_clay_biru>=(2*demand_ayam):
            bahan_clay_merah-=1*demand_ayam
            bahan_clay_biru-=2*demand_ayam
            bahan_clay_ungu+=(demand_kupukupu*bahan_clay_merah)+(demand_kupukupu*bahan_clay_biru)
            bahan_clay_merah-=demand_kupukupu*bahan_clay_ungu
            bahan_clay_biru-=demand_kupukupu*bahan_clay_ungu
            if bahan_clay_ungu>=(3*demand_kupukupu) and bahan_clay_merah>=(1*demand_kupukupu) and bahan_clay_biru>=(1*demand_kupukupu):
                    print("Pesanan dapat diterima oleh Nona Sal")
            else: print("Pesanan tidak dapat diterima oleh Nona Sal")
else:
    print("Pesanan tidak dapat diterima oleh Nona Sal")
