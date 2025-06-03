---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STLS-0001
nama_algoritma: Linear Search
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟠 O(n)
memory_complexity: 🟢 O(1)
sumber: programiz.com
date_learned: 2025-04-10T22:14:00
tags:
  - array
  - search
  - linear-search
---
#array #search #linear-search

---
# Linear Search Algorithm

Pencarian linear adalah algoritma pencarian secara berurutan di mana kita mulai dari salah satu ujung dan memeriksa setiap elemen dalam daftar sampai elemen yang diinginkan ditemukan. Ini adalah algoritma pencarian yang paling sederhana.

## Algoritma Linear Search
Langkah-langkah berikut dilakukan untuk mencari elemen `k = 1` dalam daftar di bawah ini.

![[Linear Search Algorithm-1.png]]

1. Mulai dari _element_ pertama, bandingkan `k` dengan setiap _element_ `x`.
   ![[Linear Search Algorithm-2.png]]
2. Jika `x == k`, kembalikan nilai index.
   
   ![[Linear Search Algorithm-3.png]]
3. Jika tidak, kembalikan `not found`.

Berikut algoritma dari linear search:

```bash
LinearSearch(array, key)
  for each item in the array
    if item == value
      return its index
```
# Contoh Algoritma Linear Search

```cpp
// Linear Search in C++

#include <iostream>
using namespace std;

int search(int array[], int n, int x) {

  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}
```

### Bonus Versi Python

```py
# Linear Search in Python


def linearSearch(array, n, x):

    # Going through array sequencially
    for i in range(0, n):
        if (array[i] == x):
            return i
    return -1


array = [2, 4, 0, 1, 9]
x = 1
n = len(array)
result = linearSearch(array, n, x)
if(result == -1):
    print("Element not found")
else:
    print("Element found at index: ", result)
```
# Linear Search Complexity
## Time Complexity
Karena dilakukan perulangan ke semua index, maka kompleksitasnya menjadi $O(n)$.
## Space Complexity 
Komnplesitas ruang adalah $O(1)$.
# Aplikasi Linear Search
1. Biasa digunakan untuk pencarian nilai dengan array < 100.
## Keunggulan dan kelemahan
### Keunggulan Linear Search
- **Implementasi sederhana**: Mudah dipahami dan diimplementasikan, bahkan untuk pemula.
    
- **Tidak memerlukan _sorting_**: _Linear search_ dapat bekerja pada _list_ yang tidak terurut.
    
- **Tidak membutuhkan memori tambahan**: Tidak menggunakan struktur data tambahan seperti _stack_, _queue_, atau _recursive call_.
    
- **Cocok untuk _list_ kecil**: Efisien saat digunakan untuk _list_ yang berukuran kecil.
### Kelemahan Linear Search
- **Lambat untuk _list_ besar**: Kompleksitas waktu $O(n)$ membuatnya tidak efisien untuk _list_ besar.
    
- **Tidak optimal**: Membandingkan setiap _element_ satu per satu, bahkan jika _element_ yang dicari ada di akhir _list_.
    
- **Tidak memanfaatkan struktur data terurut**: Tidak mendapat keuntungan apa pun jika _list_ sudah di-_sort_.
## Kesimpulan
Simple, namun bukan yang paling efisien.