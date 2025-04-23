---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STRS-0001
nama_algoritma: Radix Sort
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: ⚪O(n * d)
memory_complexity: ⚪O(n + k) ✅ → Stable
sumber: chatgpt.com, Programiz.com, Google AI, geeksforgeeks.com & w3schools.com & deepseek.com
date_learned: 2025-04-18T00:31:00
tags:
  - array
  - sorting
  - radix-sort
---
#array #radix-sort #sorting 

---
# Radix Sort Algorithm

**Radix sort** adalah algoritma pengurutan yang mengurutkan elemen dengan terlebih dahulu mengelompokkan digit-digit individu berdasarkan nilai tempat yang sama. Setelah itu, elemen diurutkan berdasarkan urutan menaik/menurun.

Misalnya, kita memiliki sebuah array dengan 8 elemen. Pertama, kita akan mengurutkan elemen berdasarkan nilai pada satuan (unit place). Lalu, kita akan mengurutkan elemen berdasarkan nilai pada puluhan (tenth place). Proses ini terus berlanjut hingga mencapai tempat bernilai paling signifikan terakhir.

Misalkan array awal adalah `[121, 432, 564, 23, 1, 45, 788]`. Array ini diurutkan menggunakan radix sort sebagaimana ditunjukkan pada gambar di bawah.

![[Radix Sort Algorithm-1.png]]

Harap pelajari **counting sort** terlebih dahulu sebelum membaca artikel ini karena **counting sort digunakan sebagai algoritma pengurutan perantara dalam radix sort**.
## Algoritma Radix Sort

1. Temukan elemen terbesar dalam array, yaitu `max`. Misalkan **X** adalah jumlah digit dalam `max`. Nilai **X** dihitung karena kita harus memproses semua nilai tempat yang signifikan dari setiap elemen. 
   
   Pada array `[121, 432, 564, 23, 1, 45, 788]`, elemen terbesar adalah `788`. Ia memiliki **3 digit**, sehingga perulangan harus berjalan sampai ke tempat ratusan (sebanyak 3 kali).

2. Selanjutnya, proses setiap nilai tempat signifikan satu per satu. 
   
   Gunakan teknik pengurutan yang **stabil** untuk mengurutkan digit pada setiap nilai tempat signifikan. Dalam hal ini, kita menggunakan **counting sort**. 
   
   Pertama, urutkan elemen berdasarkan digit satuan (**X = 0**).
   ![[Radix Sort Algorithm-2.png]]
3. Sekarang, urutkan elemen berdasarkan digit pada **tempat puluhan**.
   
   ![[Radix Sort Algorithm-3.png]]
4. Terakhir, urutkan elemen berdasarkan digit pada **tempat ratusan**.
   
   ![[Radix Sort Algorithm-4.png]]
## Pseudocode Radix Sort

```bash
radixSort(array)
  d <- jumlah digit terbesar pada elemen terbesar
  buat d ember dengan ukuran 0-9
  untuk i <- 0 hingga d
    urutkan elemen berdasarkan digit ke-i menggunakan countingSort

countingSort(array, d)
  max <- temukan elemen terbesar pada digit ke-d
  inisialisasi array count dengan semua nol
  untuk j <- 0 hingga ukuran array
    temukan jumlah total setiap digit unik pada tempat ke-d elemen dan
    simpan jumlahnya pada index ke-j di array count
  untuk i <- 1 hingga max
    temukan jumlah kumulatif dan simpan di array count
  untuk j <- ukuran array hingga 1
    kembalikan elemen ke array
    kurangi count setiap elemen yang dikembalikan sebanyak 1
```

Versi original:

```bash
radixSort(array)
  d <- maximum number of digits in the largest element
  create d buckets of size 0-9
  for i <- 0 to d
    sort the elements according to ith place digits using countingSort

countingSort(array, d)
  max <- find largest element among dth place elements
  initialize count array with all zeros
  for j <- 0 to size
    find the total count of each unique digit in dth place of elements and
    store the count at jth index in count array
  for i <- 1 to max
    find the cumulative sum and store it in count array itself
  for j <- size down to 1
    restore the elements to array
    decrease count of each element restored by 1
```
# Contoh Algoritma Radix Sort
Versi C++:

```cpp
// Radix Sort dalam Pemrograman C++

#include <iostream>
using namespace std;

// Fungsi untuk mendapatkan elemen terbesar dari array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Menggunakan counting sort untuk mengurutkan elemen berdasarkan tempat yang signifikan
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Hitung jumlah elemen
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Hitung jumlah kumulatif
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Tempatkan elemen-elemen dalam urutan yang sudah diurutkan
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Fungsi utama untuk menerapkan radix sort
void radixsort(int array[], int size) {
  // Dapatkan elemen maksimum
  int max = getMax(array, size);

  // Terapkan counting sort untuk mengurutkan elemen berdasarkan nilai tempat
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Cetak array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Kode utama
int main() {
  int array[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}
```

### Bonus versi Python

```py
# Radix sort in Python
# Using counting sort to sort the elements in the basis of significant places
def countingSort(array, place):
    size = len(array)
    output = [0] * size
    count = [0] * 10

    # Calculate count of elements
    for i in range(0, size):
        index = array[i] // place
        count[index % 10] += 1

    # Calculate cumulative count
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Place the elements in sorted order
    i = size - 1
    while i >= 0:
        index = array[i] // place
        output[count[index % 10] - 1] = array[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, size):
        array[i] = output[i]


# Main function to implement radix sort
def radixSort(array):
    # Get maximum element
    max_element = max(array)

    # Apply counting sort to sort elements based on place value.
    place = 1
    while max_element // place > 0:
        countingSort(array, place)
        place *= 10


data = [121, 432, 564, 23, 1, 45, 788]
radixSort(data)
print(data)
```
# Radix Sort Complexity
## Time Complexity
> Karena radix sort adalah algoritma non-komparatif, ia memiliki keunggulan dibandingkan algoritma pengurutan komparatif. 
> 
> Untuk radix sort yang menggunakan counting sort sebagai algoritma pengurutan stabil sementara, kompleksitas waktunya adalah $O(d(n+k))$.
### Best Case (Kasus Terbaik) - $O(n \cdot d)$
**O(n * d)** juga berlaku untuk kasus rata-rata. Di sini, **n** adalah jumlah elemen yang akan diurutkan dan **d** adalah jumlah digit pada angka terbesar dalam array yang sedang diurutkan.
### Average Case (Kasus Rata-rata) - $O(n \cdot d)$
- Pada **kasus rata-rata**, seperti halnya pada kasus terbaik, waktu yang dibutuhkan oleh **Radix Sort** adalah **O(n * k)**.
    
- **n** adalah jumlah elemen dalam array, dan **k** adalah jumlah digit dalam elemen terbesar (sehingga **k** adalah panjang maksimal elemen yang harus diperiksa).

### Worst Case (Kasus Terburuk) - $O(n \cdot d)$
Pada **kasus terburuk**, Radix Sort tetap beroperasi dengan **O(n * d)**, karena proses pengurutan berdasarkan digit tidak berubah, terlepas dari apakah elemen-elemen tersebut sudah terurut atau tidak.
### Ringkasan
**Time complexity** Radix Sort adalah **O(n * d)**, di mana:

- **n** adalah jumlah elemen yang akan diurutkan
    
- **d** adalah jumlah digit dalam angka terbesar yang ada dalam array.

| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n \cdot d)$     |
| Average Case | $O(n \cdot d)$     |
| Worst Case   | $O(n \cdot d)$     |
## Space Complexity dan Stability
### Space Complexity
- **Space Complexity** pada **Radix Sort** tergantung pada jumlah elemen yang perlu disalin atau diproses selama pengurutan.
    
- **Radix Sort** menggunakan algoritma **Counting Sort** sebagai langkah pengurutan untuk setiap digit. Dalam **Counting Sort**, kita memerlukan array tambahan untuk menyimpan hasil sortir dan untuk menghitung frekuensi elemen berdasarkan digit.
- Kompleksitas memory radi sort adalah **O(n + k)**, di mana:

	- **n** adalah jumlah elemen dalam array yang perlu disortir.
	    
	- **k** adalah jumlah nilai unik untuk setiap digit (biasanya **k = 10** untuk digit 0-9).
	    

Dimana **n** diperlukan untuk menyimpan array yang akan diurutkan, dan **k** diperlukan untuk menghitung frekuensi dan mengembalikan hasil sortir (menggunakan array hitung dan array output).
### Stability
- **Stability** adalah sifat dari algoritma pengurutan yang mempertahankan urutan relatif elemen dengan nilai yang sama.
    
- **Radix Sort** adalah algoritma yang **stabil**. Ini berarti bahwa jika dua elemen memiliki nilai yang sama, urutan relatif mereka yang sudah ada sebelumnya dalam array akan dipertahankan setelah pengurutan.

## Kesimpulan
| Faktor Complexity | Nilai          |
| ----------------- | -------------- |
| Best Case         | $O(n \cdot d)$ |
| Average Case      | $O(n \cdot d)$ |
| Worst Case        | $O(n \cdot d)$ |
| Space Complexity  | $O(n + k)$     |
| Stability         | Stable         |
# Aplikasi Radix Sort
Radix Sort sering digunakan dalam pengurutan angka atau string dengan panjang tetap, seperti kode pos, nomor telepon, atau urutan angka besar, karena dapat melakukan pengurutan lebih efisien dibandingkan algoritma pengurutan komparatif dalam kasus tertentu.
## Keunggulan dan kelemahan
### Keunggulan Radix Sort
- **Efisien untuk Data dengan Banyak Digit Terbatas**
    
    - Radix Sort sangat efektif jika data yang diurutkan memiliki banyak digit terbatas dan nilai digitnya relatif kecil. Contohnya, pengurutan angka besar yang memiliki jumlah digit tetap atau kode pos.
        
- **Waktu Pengurutan yang Cepat pada Kasus Tertentu**
    
    - Jika jumlah digit yang harus diproses (d) relatif kecil, Radix Sort bisa lebih cepat dibandingkan algoritma pengurutan komparatif lain seperti **QuickSort** atau **MergeSort** yang memiliki kompleksitas waktu **O(n log n)**. Radix Sort memiliki kompleksitas waktu **O(n * d)**, yang membuatnya lebih efisien pada data dengan banyak digit terbatas.
        
- **Tidak Bergantung pada Perbandingan**
    
    - Radix Sort adalah algoritma non-komparatif, yang berarti tidak menggunakan perbandingan antara elemen untuk mengurutkan. Ini membuatnya memiliki performa yang lebih baik pada data dengan jumlah besar.
        
- **Stabil**
    
    - Radix Sort adalah algoritma yang stabil, yang berarti urutan relatif elemen dengan nilai yang sama tetap terjaga selama proses pengurutan. Ini sangat berguna untuk aplikasi yang memerlukan urutan elemen yang sama tetap dipertahankan.
### Kelemahan Radix Sort
- **Memerlukan Ruang Memori Tambahan**
    
    - Radix Sort memerlukan ruang tambahan untuk array hitung dan array output, sehingga **Space Complexity**-nya adalah **O(n + k)**. Ini dapat menjadi masalah ketika bekerja dengan data yang sangat besar atau perangkat dengan memori terbatas.
        
- **Tidak Efisien untuk Data dengan Banyak Digit**
    
    - Jika elemen yang diurutkan memiliki banyak digit (misalnya, angka dengan banyak digit atau string panjang), waktu yang dibutuhkan akan meningkat seiring bertambahnya jumlah digit **d**. Dalam kasus ini, algoritma komparatif mungkin lebih efisien.
        
- **Tidak Cocok untuk Data dengan Panjang yang Sangat Berbeda**
    
    - Radix Sort lebih cocok untuk data yang memiliki panjang digit yang relatif konsisten, seperti angka atau string pendek dengan panjang tetap. Jika elemen yang diurutkan sangat bervariasi panjangnya, Radix Sort bisa kurang efisien.
## Kesimpulan
Radix Sort adalah algoritma pengurutan yang sangat efisien untuk data dengan banyak digit terbatas, terutama ketika elemen yang diurutkan adalah angka atau string dengan panjang tetap. Algoritma ini memiliki **time complexity** **O(n * d)**, di mana **n** adalah jumlah elemen dan **d** adalah jumlah digit pada angka terbesar. Dengan **space complexity** **O(n + k)**, Radix Sort menjadi pilihan yang sangat baik untuk pengurutan angka atau data dengan nilai yang terbatas, tetapi bisa menjadi kurang efisien jika elemen yang diurutkan memiliki banyak digit atau panjang yang sangat bervariasi.