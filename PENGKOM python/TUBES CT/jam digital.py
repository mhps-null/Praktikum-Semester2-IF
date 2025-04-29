import tkinter as tk

class SevenSegmentDisplay:
    def __init__(self, root):
        self.root = root
        self.root.title("Seven Segment Display")

        # Canvas untuk menampilkan angka
        self.canvas = tk.Canvas(root, width=200, height=300, bg="white")
        self.canvas.pack()

        # Posisi segmen (x1, y1, x2, y2)
        self.segments = {
            "a": self.canvas.create_rectangle(50, 20, 150, 40, fill="gray"),
            "b": self.canvas.create_rectangle(150, 40, 170, 120, fill="gray"),
            "c": self.canvas.create_rectangle(150, 140, 170, 220, fill="gray"),
            "d": self.canvas.create_rectangle(50, 220, 150, 240, fill="gray"),
            "e": self.canvas.create_rectangle(30, 140, 50, 220, fill="gray"),
            "f": self.canvas.create_rectangle(30, 40, 50, 120, fill="gray"),
            "g": self.canvas.create_rectangle(50, 120, 150, 140, fill="gray"),
        }

        # Input angka
        self.entry = tk.Entry(root, font=("Arial", 20), justify="center")
        self.entry.pack(pady=10)

        # Tombol untuk menampilkan angka
        self.button = tk.Button(root, text="Tampilkan", command=self.display_number)
        self.button.pack()

    def display_number(self):
        number = self.entry.get()
        if number.isdigit() and 0 <= int(number) <= 9:
            self.update_segments(int(number))
        else:
            print("Masukkan angka antara 0-9.")

    def update_segments(self, number):
        # Konfigurasi segmen untuk angka 0-9
        numbers_to_segments = {
            0: ["a", "b", "c", "d", "e", "f"],
            1: ["b", "c"],
            2: ["a", "b", "g", "e", "d"],
            3: ["a", "b", "g", "c", "d"],
            4: ["f", "g", "b", "c"],
            5: ["a", "f", "g", "c", "d"],
            6: ["a", "f", "g", "e", "c", "d"],
            7: ["a", "b", "c"],
            8: ["a", "b", "c", "d", "e", "f", "g"],
            9: ["a", "b", "c", "d", "f", "g"],
        }

        # Aktifkan segmen yang sesuai
        active_segments = numbers_to_segments[number]
        for segment, rect in self.segments.items():
            if segment in active_segments:
                self.canvas.itemconfig(rect, fill="red")  # Segmen aktif (warna merah)
            else:
                self.canvas.itemconfig(rect, fill="gray")  # Segmen mati (warna abu-abu)


# Menjalankan program
root = tk.Tk()
app = SevenSegmentDisplay(root)
root.mainloop()
