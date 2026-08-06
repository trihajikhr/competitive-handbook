---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STIS0001
nama_algoritma: insertion sort algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟠 O(n) >  🟣 O(n²) > 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
sumber: programiz.com & geeksforgeeks.com
date_learned: 2025-03-06T19:45:00
tags:
  - array
  - sorting
  - insertion-sort
---
#array #sorting #insertion-sort

---
# Insertion Sort Algorithm

_Insertion sort_ adalah algoritma pengurutan yang menempatkan elemen yang belum terurut ke posisi yang sesuai dalam setiap iterasi.

_Insertion sort_ bekerja mirip seperti saat kita menyusun kartu di tangan dalam permainan kartu.

Kita menganggap bahwa kartu pertama sudah terurut, lalu kita memilih satu kartu yang belum terurut. Jika kartu tersebut lebih besar dari kartu di tangan, maka diletakkan di sebelah kanan, jika lebih kecil, maka diletakkan di sebelah kiri. Dengan cara yang sama, kartu-kartu lain yang belum terurut akan diambil dan ditempatkan di posisi yang tepat.

Pendekatan serupa digunakan dalam _insertion sort_.
## Cara Kerja Insertion Sort

Misalkan kita perlu mengurutkan array berikut.

![[Insertion Sort Algorithm-1.png]]

1. Elemen pertama dalam array dianggap sudah terurut. Ambil elemen kedua dan simpan secara terpisah dalam **key**.
   
   Bandingkan **key** dengan elemen pertama. Jika elemen pertama lebih besar dari **key**, maka **key** ditempatkan di depan elemen pertama.
   
   ![[Insertion Sort Algorithm-2.png]]
2. Sekarang, dua elemen pertama sudah terurut.
   
   Ambil elemen ketiga dan bandingkan dengan elemen-elemen di sebelah kirinya. Tempatkan elemen tersebut tepat di belakang elemen yang lebih kecil darinya. Jika tidak ada elemen yang lebih kecil, maka tempatkan di awal array.
   
   ![[Insertion Sort Algorithm-3.png]]
3. Dengan cara yang sama, tempatkan setiap elemen yang belum terurut di posisi yang benar.
   
   ![[Insertion Sort Algorithm-4.png]]
   ![[Insertion Sort Algorithm-5.png]]
## Algoritma Insertion Sort

```cpp
insertionSort(array)
  mark first element as sorted
  for each unsorted element X
    'extract' the element X
    for j <- lastSortedIndex down to 0
      if current element j > X
        move sorted element to the right by 1
    break loop and insert X here
end insertionSort
```

Atau:

```cpp
insertionSort(array)
  tandai elemen pertama sebagai terurut
  untuk setiap elemen X yang belum terurut
    'ambil' elemen X
    untuk j <- lastSortedIndex turun ke 0
      jika elemen j saat ini > X
        geser elemen yang sudah terurut ke kanan sejauh 1
    hentikan loop dan sisipkan X di sini
end insertionSort
```
# Contoh Insertion Sort

```cpp
// Insertion sort dalam C++

#include <iostream>
using namespace std;

// Fungsi untuk mencetak array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Bandingkan key dengan setiap elemen di sebelah 
    // kirinya hingga ditemukan elemen yang lebih kecil darinya.
    // Untuk urutan menurun, ubah key<array[j] menjadi key>array[j].
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Kode utama
int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  cout << "Array yang telah diurutkan dalam urutan menaik:\n";
  printArray(data, size);
}
```

## Bonus Python

```py
# Insertion sort in Python


def insertionSort(array):

    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key


data = [9, 5, 1, 4, 3]
insertionSort(data)
print('Sorted Array in Ascending Order:')
print(data)
```
# Insertion Sort Complexity
## Time Complexity

Insertion Sort merupakan salah satu algoritma sorting yang sederhana tetapi lebih efisien dibandingkan Bubble Sort dalam beberapa kasus. Berikut adalah analisis kompleksitasnya dalam tiga skenario:

### Best Case (Kasus Terbaik) - $O(n)$

- Kasus terbaik terjadi ketika array sudah dalam keadaan terurut secara menaik.
- Dalam skenario ini, setiap elemen hanya dibandingkan dengan elemen sebelumnya, tanpa ada perpindahan posisi.
- Karena hanya dilakukan **n-1** perbandingan dan tidak ada operasi pemindahan elemen, kompleksitas waktu dalam kasus ini adalah **O(n)**.

### Average Case (Kasus Rata-rata) - $O(n^2)$

- Dalam skenario umum, elemen-elemen berada dalam urutan acak.
- Setiap elemen dibandingkan dengan elemen sebelumnya dan dipindahkan ke posisi yang sesuai dalam sub-array yang sudah terurut.
- Jumlah total operasi perpindahan elemen secara rata-rata adalah **O(n²)**.

### Worst Case (Kasus Terburuk) - $O(n^2)$

- Kasus terburuk terjadi ketika array dalam keadaan benar-benar terbalik, yaitu dalam urutan menurun.
- Setiap elemen harus dibandingkan dengan semua elemen sebelumnya dan dipindahkan ke posisi yang benar, menyebabkan jumlah operasi maksimal terjadi.
- Kompleksitas waktu dalam kasus ini adalah **O(n²)** karena setiap elemen membutuhkan perbandingan dan perpindahan dalam setiap iterasi.

### Ringkasan

| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n)$             |
| Average Case | $O(n^2)$           |
| Worst Case   | $O(n^2)$           |


## Space Complexity dan Stability

### Space Complexity

Insertion Sort menggunakan $O(1)$ ruang tambahan karena sorting dilakukan secara **in-place**, tanpa memerlukan struktur data tambahan.

### Stability

Insertion Sort adalah **stable sorting algorithm**, karena elemen dengan nilai yang sama tidak akan bertukar posisi relatif selama proses sorting.

## Kesimpulan

| Faktor Complexity | Nilai             |
| ----------------- | ----------------- |
| Best Case         | $O(n)$            |
| Average Case      | $O(n^2)$          |
| Worst Case        | $O(n^2)$          |
| Space Complexity  | $O(1)$ (in-place) |
| Stability         | Stable            |

# Aplikasi Insertion Sort
Aplikasi insertion sort dapat diterapkan pada kasus-kasus berikut:

- **Jika array memiliki jumlah elemen yang kecil** → Insertion Sort bekerja dengan kompleksitas **O(n²)** pada kasus rata-rata dan terburuk, namun karena overhead-nya rendah dan pengolahan dilakukan **in-place**, algoritma ini sering kali lebih cepat untuk ukuran kecil (misalnya, ≤10 elemen).
    
- **Jika hanya beberapa elemen yang belum terurut** → Insertion Sort memiliki **O(n)** pada kasus terbaik, yaitu ketika array hampir terurut. Jika hanya beberapa elemen yang perlu dipindahkan ke posisi yang benar, algoritma ini dapat menyelesaikan pengurutan dengan cepat dibandingkan algoritma berbasis **divide and conquer** seperti Merge Sort atau Quick Sort yang masih akan memproses seluruh array.
    

Kesimpulannya, **Insertion Sort sangat cocok digunakan pada array kecil atau ketika array hampir terurut.**
## Keunggulan dan kelemahan
### Keunggulan Insertion Sort
- Sederhana dan mudah untuk diimplementasikan.
- Algoritma pengurutan yang stabil.
- Efisien untuk daftar kecil dan daftar yang hampir terurut.
- Efisien dalam hal ruang karena merupakan algoritma in-place.
- Adaptif. Jumlah inversi berbanding langsung dengan jumlah pertukaran. Sebagai contoh, tidak ada pertukaran yang terjadi pada array yang sudah terurut dan hanya membutuhkan waktu O(n).
### Kelemahan Insertion Sort
- Tidak efisien untuk daftar besar.
- Tidak seefisien algoritma pengurutan lain (misalnya, merge sort, quick sort) untuk sebagian besar kasus.
## Kesimpulan