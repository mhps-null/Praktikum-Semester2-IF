import matplotlib.pyplot as plt
import numpy as np

# Data contoh
countries = ['Australia', 'Brazil', 'Canada', 'Germany', 'India', 'Japan', 'UK', 'USA']
views = [50000, 75000, 60000, 80000, 2500000, 90000, 85000, 95000]

plt.figure(figsize=(10, 6))
plt.bar(countries, views)
plt.yscale('log')  # Skala logaritmik
plt.title('Views by Country (Log Scale)')
plt.ylabel('Views (log scale)')
plt.xticks(rotation=45)
plt.grid(True, which="both", ls="--")
plt.show()