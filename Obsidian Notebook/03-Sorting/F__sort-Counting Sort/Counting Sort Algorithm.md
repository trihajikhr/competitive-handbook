---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STCS-0001
nama_algoritma: Counting Sort
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: ⚪O(n * k)
memory_complexity: ⚪O(n * k) ✅ → Stable
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
### Best Case (Kasus Terbaik) - $O(n + k)$
Counting Sort bekerja sangat efisien ketika rentang nilai elemen (nilai maksimum - nilai minimum) relatif kecil dibandingkan jumlah elemen.  
**Waktu yang dibutuhkan: O(n + k)**

- _n_ adalah jumlah elemen dalam array.
    
- _k_ adalah nilai maksimum dari elemen yang akan disortir.  
    Jika _k_ mendekati _n_, maka performanya hampir linear: **O(n)**.
### Average Case (Kasus Rata-rata) - $O(n + k)$
Rata-rata, Counting Sort juga memiliki performa yang baik jika nilai maksimum elemen tidak terlalu besar.  
**Waktu yang dibutuhkan: O(n + k)**

- Counting Sort tidak tergantung pada urutan awal elemen.
    
- Asalkan _k_ tidak terlalu besar, performa tetap efisien.  
    Namun jika _k_ jauh lebih besar dari _n_, efisiensinya turun.

### Worst Case (Kasus Terburuk) - $O(n + k)$
Terjadi saat nilai maksimum elemen (_k_) sangat besar dibanding jumlah elemen (_n_), misalnya menyortir 10 angka antara 1 sampai 1.000.000.  
**Waktu yang dibutuhkan: O(n + k)**

- Ini berarti kompleksitas bisa sangat besar jika _k_ >> _n_.
    
- Penggunaan memori juga menjadi tidak efisien.
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n + k)$         |
| Average Case | $O(n + k)$         |
| Worst Case   | $O(n + k)$         |
## Space Complexity dan Stability
### Space Complexity
Counting Sort membutuhkan memori tambahan untuk:

- Array _count_ berukuran _k_ (nilai maksimum elemen + 1)
    
- Array _output_ berukuran _n_ (jumlah elemen input)
    

**Total Space: O(n + k)**

- _n_ untuk menyimpan hasil akhir
    
- _k_ untuk menyimpan frekuensi tiap nilai
    

Jika _k_ jauh lebih besar dari _n_, penggunaan memori bisa menjadi sangat tidak efisien.
### Stability
**Counting Sort adalah algoritma yang stabil**

- Elemen dengan nilai yang sama akan tetap mempertahankan urutan relatifnya dari input ke output.
    
- Hal ini penting jika digunakan untuk sorting data yang memiliki _key_ yang sama, misalnya saat melakukan **radix sort** (yang sangat bergantung pada stability).
    

Untuk menjaga stabilitas, Counting Sort menelusuri input dari **belakang ke depan** saat membangun array output.

## Kesimpulan
| Faktor Complexity | Nilai      |
| ----------------- | ---------- |
| Best Case         | $O(n + k)$ |
| Average Case      | $O(n + k)$ |
| Worst Case        | $O(n + k)$ |
| Space Complexity  | $O(n+k)$   |
| Stability         | Stable     |
# Aplikasi Counting Sort
Counting Sort sangat cocok digunakan ketika:

- Kita mengetahui bahwa semua elemen berada dalam **rentang nilai terbatas** (misalnya 0 hingga 1000).
    
- Kita memerlukan **sorting yang sangat cepat** dalam kasus tertentu (lebih cepat dari O(n log n) jika kondisinya tepat).
    
- Kita membutuhkan **algoritma yang stabil**, terutama untuk digunakan dalam **Radix Sort**.
### Contoh Aplikasi:

- Menyortir nilai ujian siswa (skor 0–100).
    
- Menyortir frekuensi karakter dalam string (misalnya untuk membangun histogram atau analisis frekuensi).
    
- Menyortir data numerik dalam sistem real-time dengan rentang nilai terbatas.
## Keunggulan dan kelemahan
### Keunggulan Counting Sort
- ✅ **Kompleksitas waktu O(n + k)** → Lebih cepat dari algoritma comparison-based (O(n log n)) dalam kondisi tertentu.
    
- ✅ **Stabil** → Tidak mengubah urutan elemen dengan nilai yang sama.
    
- ✅ **Non-comparison based** → Tidak membandingkan elemen satu sama lain, sehingga bisa sangat cepat.
    
- ✅ Cocok untuk **data diskrit** dengan **range kecil**, misalnya integer positif kecil.
### Kelemahan Counting Sort
- ❌ **Tidak efisien untuk rentang nilai besar** → Jika elemen berkisar dari 1 sampai 1.000.000, maka array count akan sangat besar.
    
- ❌ **Bukan in-place** → Memerlukan memori tambahan O(n + k).
    
- ❌ **Hanya bekerja untuk tipe data yang bisa dihitung secara langsung** (biasanya integer atau dapat dipetakan ke integer).
    
- ❌ Kurang fleksibel dibanding algoritma sorting umum seperti Quick Sort atau Merge Sort.
## Kesimpulan
Counting Sort adalah algoritma sorting yang sangat efisien untuk data dengan **nilai diskrit dalam rentang yang kecil**. Dengan kompleksitas waktu **O(n + k)** dan sifat **stabil**, algoritma ini unggul dalam banyak kasus spesifik seperti sorting skor, karakter, atau data numerik yang terbatas.

Namun, Counting Sort memiliki keterbatasan dalam hal penggunaan memori dan fleksibilitas. Ia **tidak cocok** untuk data dengan **rentang nilai sangat besar** atau **tipe data non-integer**.

> ✅ Gunakan Counting Sort ketika:
> 
> - Jumlah elemen besar
>     
> - Rentang nilai kecil
>     
> - Memerlukan sorting stabil
>     

> ❌ Hindari Counting Sort ketika:
> 
> - Rentang nilai sangat besar
>     
> - Memori terbatas
>     
> - Tipe data kompleks atau bukan integer
>     

Dengan memahami kelebihan dan kekurangannya, kita bisa memilih Counting Sort secara tepat untuk kasus yang sesuai.