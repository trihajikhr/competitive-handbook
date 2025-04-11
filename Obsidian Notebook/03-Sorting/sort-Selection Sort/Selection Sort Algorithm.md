---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STSS0001
nama_algoritma: selection sort algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²) > 🟣 O(n²)  > 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
sumber: programiz.com & geeksforgeeks.com
date_learned: 2025-03-06T13:54:00
tags:
  - array
  - sorting
  - selection-sort
---
#array  #sorting  #selection-sort

---
# Selection Sort Algorithm

Selection sort adalah algoritma sorting yang memilih elemen terkecil dari daftar yang belum terurut pada setiap iterasi dan menempatkan elemen tersebut di awal daftar yang belum terurut.
## Cara Kerja Selection Sort

1. Tetapkan elemen pertama sebagai `minimum`.
   ![[Selection Sort Algorithm-1.png]]
2. Bandingkan nilai `minimum` dengan elemen kedua. Jika elemen kedua lebih kecil dari `minimum`, tetapkan elemen kedua sebagai `minimum`.
   
   Bandingkan nilai `minimum` dengan elemen ketiga. Jika elemen ketiga lebih kecil, tetapkan `minimum` ke elemen ketiga, jika tidak, biarkan seperti itu. Proses ini berlanjut hingga elemen terakhir.
   
   ![[Selection Sort Algorithm-2.png]]
3. Setelah setiap iterasi, nilai `minimum` ditempatkan di awal daftar yang belum terurut.
   
   ![[Selection Sort Algorithm-3.png]]
4. Pada setiap iterasi, pengindeksan dimulai dari elemen pertama yang belum terurut. Langkah 1 hingga 3 diulangi hingga semua elemen berada pada posisi yang benar.
   
   ![[Selection Sort Algorithm-4.png]]
   ![[Selection Sort Algorithm-5.png]]
   ![[Selection Sort Algorithm-6.png]]
   ![[Selection Sort Algorithm-7.png]]
## Algoritma Selection Sort

```cpp
selectionSort(array, size)
  for i from 0 to size - 1 do
    set i as the index of the current minimum
    for j from i + 1 to size - 1 do
      if array[j] < array[current minimum]
        set j as the new current minimum index
    if current minimum is not i
      swap array[i] with array[current minimum]
end selectionSort
```

Atau:

```cpp
selectionSort(array, ukuran)
  untuk i dari 0 hingga ukuran - 1 lakukan
    tetapkan i sebagai indeks minimum saat ini
    untuk j dari i + 1 hingga ukuran - 1 lakukan
      jika array[j] < array[minimum saat ini]
        tetapkan j sebagai indeks minimum saat ini yang baru
    jika minimum saat ini bukan i
      tukar array[i] dengan array[minimum saat ini]
selesai selectionSort
```
# Contoh Algoritma Selection Sort


```cpp
// Selection sort dalam C++

#include <iostream>
using namespace std;

// fungsi untuk menukar posisi dua elemen
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// fungsi untuk mencetak array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // Untuk mengurutkan dalam urutan menurun, ubah > menjadi < di 
      // baris ini. Pilih elemen terkecil di setiap iterasi.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // tempatkan elemen terkecil di posisi yang benar
    swap(&array[min_idx], &array[step]);
  }
}

// kode utama
int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  cout << "Array yang telah diurutkan dalam urutan naik:\n";
  printArray(data, size);
}
```

## Bonus Python

```py
# Selection sort in Python


def selectionSort(array, size):
   
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
         
            # to sort in descending order, change > to < in this line
            # select the minimum element in each loop
            if array[i] < array[min_idx]:
                min_idx = i
         
        # put min at the correct position
        (array[step], array[min_idx]) = (array[min_idx], array[step])


data = [-2, 45, 0, 11, -9]
size = len(data)
selectionSort(data, size)
print('Sorted Array in Ascending Order:')
print(data)
```
# Selection Sort Complexity
## Time Complexity

Selection Sort merupakan algoritma sorting sederhana yang bekerja dengan cara mencari elemen terkecil pada setiap iterasi dan menempatkannya pada posisi yang benar. Berikut adalah analisis kompleksitas waktunya dalam tiga kasus:
### Best Case (Kasus Terbaik) - $O(n^2)$

- Kasus terbaik terjadi ketika array sudah dalam keadaan terurut.
- Namun, Selection Sort tetap harus mencari elemen terkecil pada setiap iterasi, sehingga tetap melakukan jumlah perbandingan yang sama seperti pada kasus rata-rata dan terburuk.
- Tidak ada optimasi yang memungkinkan algoritma berhenti lebih cepat.
- Oleh karena itu, kompleksitas waktu dalam kasus terbaik tetap **O(n²)**.

### Average Case (Kasus Rata-rata) - $O(n^2)$

- Dalam kondisi acak, algoritma tetap harus mencari elemen terkecil dan menukarnya pada setiap iterasi.
- Pada iterasi pertama, dilakukan **n-1** perbandingan, iterasi kedua **n-2**, dan seterusnya.
- Total jumlah perbandingan yang dilakukan adalah:   $$(n-1)+(n-2)+\dots+2+1=\frac{n(n-1)}{2}$$
- Oleh karena itu, kompleksitas waktu dalam kasus rata-rata adalah **O(n²)**.
### Worst Case (Kasus Terburuk) - $O(n^2)$

- Kasus terburuk terjadi ketika array dalam keadaan benar-benar terbalik.
- Sama seperti pada kasus rata-rata, algoritma tetap harus melakukan **O(n²)** perbandingan dan pertukaran.
- Oleh karena itu, kompleksitas waktu dalam kasus terburuk tetap **O(n²)**.

### Ringkasan

| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n²)$            |
| Average Case | $O(n²)$            |
| Worst Case   | $O(n²)$            |

## Space Complexity dan Stability

### Space Complexity

- Selection Sort menggunakan sorting in-place, yang berarti tidak memerlukan struktur data tambahan selain beberapa variabel bantu.
- Oleh karena itu, kompleksitas ruangnya adalah **O(1)**.

### Stability

- Selection Sort **bukan** algoritma yang **stable**, karena elemen dengan nilai yang sama dapat bertukar posisi relatif selama proses sorting.

## Kesimpulan

| Faktor Complexity | Nilai             |
| ----------------- | ----------------- |
| Best Case         | $O(n²)$           |
| Average Case      | $O(n²)$           |
| Worst Case        | $O(n²)$           |
| Space Complexity  | $O(1)$ (in-place) |
| Stability         | Not Stable        |

# Aplikasi Selection Sort

Selection Sort digunakan dalam situasi berikut:

- Ketika daftar yang akan diurutkan berukuran kecil.
- Ketika biaya pertukaran elemen tidak menjadi masalah.
- Ketika pengecekan terhadap semua elemen dalam daftar diperlukan.
- Ketika biaya penulisan ke memori menjadi faktor penting, seperti pada flash memory (karena jumlah penulisan/pertukaran hanya **O(n)** dibandingkan **O(n²)** pada Bubble Sort).
## Keunggulan dan kelemahan

### Keunggulan Selection Sort
- Mudah dipahami dan diimplementasikan, sehingga ideal untuk mengajarkan konsep dasar sorting.
- Hanya membutuhkan ruang ekstra **O(1)** (konstan).
- Memerlukan lebih sedikit pertukaran (atau penulisan ke memori) dibandingkan banyak algoritma standar lainnya. Hanya **Cycle Sort** yang lebih baik dalam hal jumlah penulisan ke memori. Oleh karena itu, Selection Sort bisa menjadi pilihan algoritma yang sederhana ketika penulisan ke memori berbiaya tinggi.
### Kelemahan Selection Sort
- Selection Sort memiliki kompleksitas waktu **O(n²)**, sehingga lebih lambat dibandingkan algoritma seperti **Quick Sort** atau **Merge Sort**.
- Tidak mempertahankan urutan relatif elemen yang bernilai sama, sehingga **bukan algoritma yang stable**.
## Kesimpulan