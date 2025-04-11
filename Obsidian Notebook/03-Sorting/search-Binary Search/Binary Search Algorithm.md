---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STBNS0001
nama_algoritma: Binary Search Algorithm
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟢 O(1) > 🔵 O(log n) > 🔵 O(log n)
memory_complexity: 🟢 O(1)
sumber: chatgpt.com, Programiz.com, Google AI
date_learned: 2025-04-10T23:40:00
tags:
  - search
  - array
  - binary-search
---
#array #search #binary-search

---
# Binary Search Algorithm

Binary Search adalah algoritma pencarian untuk menemukan posisi suatu elemen dalam array yang sudah diurutkan.

Dalam pendekatan ini, elemen selalu dicari di bagian tengah dari suatu bagian array.

Binary search hanya dapat diimplementasikan pada daftar elemen yang sudah diurutkan. Jika elemen-elemennya belum diurutkan, kita perlu mengurutkannya terlebih dahulu.
## Algoritma Binary Search
Algoritma Binary Search dapat diimplementasikan dengan dua cara yang dibahas di bawah ini.

- Metode Iteratif
- Metode Rekursif

Metode rekursif mengikuti pendekatan _divide and conquer_.

Langkah umum untuk kedua metode dibahas di bawah ini.

1. Array tempat pencarian akan dilakukan adalah:
   ![[Untitled-1.png]]
   Misalkan `x=4` adalah elemen yang akan dicari.

2. Atur dua penunjuk, yaitu `low` dan `high`, masing-masing pada posisi terendah dan tertinggi.
   ![[Untitled-2.png]]
3. Temukan posisi tengah `mid` dari array, yaitu `mid = (low + high)/2` dan `arr[mid] = 6`.
   
   ![[Untitled-3.png]]
4. Jika `x == arr[mid]`, maka kembalikan `mid`. Jika tidak, bandingkan elemen yang dicari dengan `arr[mid]`.

5. Jika `x > arr[mid]`, bandingkan `x` dengan elemen tengah dari elemen-elemen di sebelah kanan `arr[mid]`. Ini dilakukan dengan mengatur: `low = mid + 1`

6. Jika tidak, bandingkan `x` dengan elemen tengah dari elemen-elemen di sebelah kiri `arr[mid]`. Ini dilakukan dengan mengatur: `high = mid - 1`
   
   ![[Untitled-4.png]]
7. Ulangi langkah 3 sampai 6 sampai `low` bertemu dengan `high`.
   
   ![[Binary Search Algorithm-1.png]]
8. `x=4` ditemukan.
   
   ![[Binary Search Algorithm-2.png]]
### Penjelasan Algoritma Binary Search
#### Metode Iterasi:

```cpp
do until the pointers low and high meet each other.
    mid = (low + high)/2
    if (x == arr[mid])
        return mid
    else if (x > arr[mid]) // x is on the right side
        low = mid + 1
    else                       // x is on the left side
        high = mid - 1
```

#### Metode Rekursif

```cpp
binarySearch(arr, x, low, high)
    if low > high
        return False 
    else
        mid = (low + high) / 2 
        if x == arr[mid]
            return mid
        else if x > arr[mid]        // x is on the right side
            return binarySearch(arr, x, mid + 1, high)
        else                               // x is on the left side
            return binarySearch(arr, x, low, mid - 1)
```
# Contoh Algoritma Binary Search
```cpp
// Binary Search dalam C++

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  
  // Ulangi sampai penunjuk low dan high bertemu
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (x == array[mid])
      return mid;

    if (x > array[mid])
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Tidak ditemukan");
  else
    printf("Elemen ditemukan pada indeks %d", result);
}

```

### Bonus versi Python
```py
# Binary Search in python


def binarySearch(array, x, low, high):

    # Repeat until the pointers low and high meet each other
    while low <= high:

        mid = low + (high - low)//2

        if x == array[mid]:
            return mid

        elif x > array[mid]:
            low = mid + 1

        else:
            high = mid - 1

    return -1


array = [3, 4, 5, 6, 7, 8, 9]
x = 4

result = binarySearch(array, x, 0, len(array)-1)

if result != -1:
    print("Element is present at index " + str(result))
else:
    print("Not found")
```
# Binary Search Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - $O(1)$
Terjadi ketika elemen yang dicari langsung berada di posisi tengah.
### Average Case (Kasus Rata-rata) - $O(log\; n)$
Kasus rata-rata tetap melakukan $O(log \;n)$ pencarian.
### Worst Case (Kasus Terburuk) - $O(log\; n)$
Array dibagi dua terus-menerus sampai elemen ditemukan atau tidak ditemukan.
### Ringkasan

## Space Complexity dan Stability
- Iteratif: `O(1)` → hanya menggunakan variabel tambahan untuk indeks (low, high, mid).
- Rekursif: `O(log n)` → karena stack rekursi saat pemanggilan fungsi berulang (jika menggunakan metode rekursif).
# Aplikasi Binary Search
- Mencari elemen dalam array yang sudah terurut.
- Mencari nilai tertentu dalam database atau tabel terurut.
- Digunakan dalam fungsi pencarian standar (seperti `std: :binary_search` di C++).
- Digunakan untuk menyelesaikan masalah optimasi dengan teknik *binary search on answer*.
- Digunakan dalam struktur data seperti Binary Search Tree (BST).
- Menentukan posisi penyisipan elemen dalam daftar terurut (seperti `lower_bound`, `upper_bound`).
## Keunggulan dan kelemahan
### Keunggulan Binary Search
- Cepat: Memiliki kompleksitas waktu $O(log \;n)$ yang jauh lebih efisien dibandingkan pencarian linear $(O(n))$.
- Efisien: Ideal untuk array besar yang sudah terurut.
- Sederhana: Mudah diimplementasikan baik secara iteratif maupun rekursif.
- Digunakan dalam banyak algoritma: Termasuk pencarian jawaban optimal dalam search space yang terurut.
### Kelemahan Binary Search
- Hanya bekerja pada data terurut: Jika data tidak terurut, harus diurutkan terlebih dahulu, yang membutuhkan $O(n \;log\; n)$ waktu.
- Kurang fleksibel pada data dinamis: Untuk array yang sering diubah (disisipkan/dihapus), perlu re-sorting.
- Kesalahan implementasi: Sering terjadi bug karena perhitungan indeks tengah (mid) atau batas low dan high tidak hati-hati.
- Rekursif membutuhkan ruang tambahan: Jika implementasi rekursif, membutuhkan ruang stack tambahan $O(log\; n)$.
## Kesimpulan

Binary Search adalah algoritma pencarian yang sangat efisien untuk menemukan elemen dalam array yang **sudah terurut**. Dengan pendekatan divide and conquer, algoritma ini memotong ruang pencarian menjadi setengah di setiap langkah, menghasilkan kompleksitas waktu O(log n).

Meskipun hanya berlaku untuk data yang terurut, kecepatan dan kesederhanaannya menjadikan Binary Search salah satu algoritma pencarian paling penting dan banyak digunakan, baik dalam pengembangan perangkat lunak sehari-hari maupun dalam kompetisi pemrograman.

Penguasaan Binary Search juga membuka pintu untuk memahami teknik yang lebih lanjut, seperti binary search on answer, lower_bound dan upper_bound, serta aplikasi dalam struktur data seperti Binary Search Tree.
