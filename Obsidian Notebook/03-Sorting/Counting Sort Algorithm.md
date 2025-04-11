---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STCS0001
nama_algoritma: Counting Sort
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: chatgpt.com, Programiz.com, Google AI
date_learned: 2025-04-10T08:17:00
tags:
  - array
  - sorting
  - counting-sort
---
#array #sorting #counting-sort

---
# Counting Sort Algorithm

Counting sort adalah algoritma pengurutan yang mengurutkan elemen-elemen dalam sebuah array dengan menghitung jumlah kemunculan setiap elemen unik di dalam array. Hasil perhitungan ini disimpan dalam sebuah array bantu (auxiliary array), dan proses pengurutan dilakukan dengan memetakan jumlah tersebut sebagai indeks dari array bantu.
## Algoritma Counting Sort
1. Temukan elemen maksimum (misalnya kita sebut sebagai _max_) dari array yang diberikan.
   
   ![[Counting Sort Algorithm-1.png]]
2. Inisialisasi sebuah array dengan panjang _max + 1_ dengan semua elemennya bernilai 0. Array ini digunakan untuk menyimpan jumlah kemunculan elemen-elemen dalam array.
   
   ![[Counting Sort Algorithm-2.png]]
3. Simpan jumlah setiap elemen pada indeks yang sesuai di array count.
   
   Sebagai contoh: jika jumlah elemen 3 adalah 2, maka 2 disimpan pada posisi ke-3 dalam array count. Jika elemen "5" tidak ada dalam array, maka 0 disimpan pada posisi ke-5.
   
   ![[Counting Sort Algorithm-3.png]]
4. Simpan jumlah setiap elemen pada indeks yang sesuai di array count. 
   
   Sebagai contoh: jika jumlah elemen 3 adalah 2, maka 2 disimpan pada posisi ke-3 dalam array count. Jika elemen "5" tidak ada dalam array, maka 0 disimpan pada posisi ke-5.
   
   ![[Counting Sort Algorithm-4.png]]
5. Temukan indeks dari setiap elemen dalam array asli di array count. Ini memberikan jumlah kumulatif. Tempatkan elemen pada indeks yang dihitung seperti yang ditunjukkan pada gambar di bawah.
   
   ![[Counting Sort Algorithm-5.png]]
6. Setelah menempatkan setiap elemen pada posisi yang benar, kurangi jumlahnya satu.

Berikut algoritmanya:

```cpp
countingSort(array, size)
  max <- find largest element in array
  initialize count array with all zeros
  for j <- 0 to size
    find the total count of each unique element and 
    store the count at jth index in count array
  for i <- 1 to max
    find the cumulative sum and store it in count array itself
  for j <- size down to 1
    restore the elements to array
    decrease count of each element restored by 1
```
# Contoh Algoritma Counting Sort
```cpp
```cpp
// Counting sort dalam pemrograman C++

#include <iostream>
using namespace std;

void countSort(int array[], int size) {
  // Ukuran array count harus setidaknya (max+1), tetapi
  // kita tidak bisa mendeklarasikannya sebagai int count(max+1) di C++
  // karena tidak mendukung alokasi memori dinamis.
  // Jadi, ukurannya ditentukan secara statis.
  int output[10];
  int count[10];
  int max = array[0];

  // Temukan elemen terbesar dalam array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Inisialisasi array count dengan semua nilai nol
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Simpan jumlah masing-masing elemen
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Simpan jumlah kumulatif dari setiap elemen array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Temukan indeks dari setiap elemen array asli dalam array count,
  // dan tempatkan elemen-elemen tersebut di array output
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Salin elemen yang telah diurutkan ke dalam array asli
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Fungsi untuk mencetak array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Kode utama
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  printArray(array, n);
}
```

### Bionus versi Python

```py
# Counting sort in Python programming


def countingSort(array):
    size = len(array)
    output = [0] * size

    # Initialize count array
    count = [0] * (max(array) + 1)

    # Store the count of each elements in count array
    for i in range(0, size):
        count[array[i]] += 1

    # Store the cummulative count
    for i in range(1, (max(array) + 1)):
        count[i] += count[i - 1]

    # Find the index of each element of the original array in count array
    # place the elements in output array
    i = size - 1
    while i >= 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1

    # Copy the sorted elements into original array
    for i in range(0, size):
        array[i] = output[i]


data = [4, 2, 2, 8, 3, 3, 1]
countingSort(data)
print("Sorted Array in Ascending Order: ")
print(data)
```
# Counting Sort Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - 
### Average Case (Kasus Rata-rata) - 

### Worst Case (Kasus Terburuk) - 
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    |                    |
| Average Case |                    |
| Worst Case   |                    |
## Space Complexity dan Stability
### Space Complexity
### Stability

## Kesimpulan
| Faktor Complexity | Nilai |
| ----------------- | ----- |
| Best Case         |       |
| Average Case      |       |
| Worst Case        |       |
| Space Complexity  |       |
| Stability         |       |
# Aplikasi Counting Sort
// Penggunan algoritma 
## Keunggulan dan kelemahan
### Keunggulan Counting Sort
### Kelemahan Counting Sort
## Kesimpulan