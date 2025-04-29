from PIL import Image, ImageDraw, ImageFont

# Dimensi gambar
width, height = 300, 100

# Membuat gambar kosong
image = Image.new("RGB", (width, height), color="black")

# Mengakses objek gambar untuk menggambar teks
draw = ImageDraw.Draw(image)

# Muat font (pastikan file font ada di direktori yang benar)
font_path = "Digital-7.ttf"  # Ganti dengan lokasi font Anda
font = ImageFont.truetype(font_path, size=50)

# Tulis teks pada gambar
text = "12:34"
text_color = "cyan"  # Warna teks
draw.text((50, 25), text, font=font, fill=text_color)

# Simpan atau tampilkan gambar
image.show()  # Menampilkan gambar
image.save("digital_clock.png")  # Menyimpan gambar ke file
