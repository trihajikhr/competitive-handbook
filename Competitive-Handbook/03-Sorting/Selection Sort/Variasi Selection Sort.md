---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STSS-V001
nama_algoritma: selection sort algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²) > 🟣 O(n²)  > 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-06-01T09:51:00
tags:
  - array
  - sorting
  - selection-sort
---

---
# Variasi Selection Sort
## 1 | Variasi Standar
Ini merupakan variasi standar dari selection sort, bagus untuk pemula untuk memahami algoritma sorting. Penjelasan lebih lengkap sudah ada di [[Selection Sort Algorithm]].

Implementasinya cukup sederahan, sebagai berikut:

```cpp
void selectionSort(vector<int> & arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]) min=j;
        }
        swap(arr[min], arr[i]);
    }
}
```

### 1.2 | Variasi Descending Order (Reverse Sorting)
Kita juga bisa mengurutkan array dengan menggunakan algoritma sorting sort, yang dimulai dari angka terbesra ke angka terkecil, caranya cukup mudah, kita hanya perlu mengganti baris atau syntax ini:

```cpp
if(arr[j] < arr[min]) min=j;
```

Menjadi seperti ini:

```cpp
if(arr[j] > arr[min]) min=j;
```

Sehingga hasil akhirnya menjadi seperti ini:

```cpp
void selectionSort(vector<int> & arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[min]) min=j;
        }
        swap(arr[min], arr[i]);
    }
}
```
## 2 | Selection Sort dari Belakang (Maximum Selection Sort)

Biasanya Selection Sort mencari elemen **minimum** dan menempatkannya di awal array. Nah, variasi ini bekerja **kebalikannya**: mencari elemen **maksimum** di bagian yang belum terurut, lalu menempatkannya di akhir array. Prosesnya tetap sama: di setiap langkah, kita cari satu elemen yang “paling ekstrem” (dalam hal ini maksimum) lalu tukar ke tempat yang tepat.

### Ilustrasi:

Misal kita punya array: `[4, 2, 5, 1, 3]`

Langkah-langkah:

- Iterasi 1: cari maksimum dari indeks 0–4 → `5`, tukar dengan indeks 4 → `[4, 2, 3, 1, 5]`
- Iterasi 2: cari maksimum dari indeks 0–3 → `4`, tukar dengan indeks 3 → `[1, 2, 3, 4, 5]`
- Dan seterusnya...

### Implementasi C++:

```cpp
void selectionSortMax(int arr[], int n) {
    for (int i = n - 1; i > 0; --i) {
        int maxIdx = 0;
        for (int j = 1; j <= i; ++j) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}
```

### Karakteristik:

- Kompleksitas waktu: $O(n²)$ untuk semua kasus.
- Jumlah pertukaran: tetap $O(n)$ di kasus terburuk.
- Tidak stabil (karena bisa mengubah urutan elemen yang nilainya sama).
- Konsepnya sama seperti Selection Sort biasa, hanya arah iterasi dan elemen yang dipilih yang berbeda.

## 3 | Double-ended Selection Sort (Bidirectional Selection Sort)

Variasi ini melakukan **dua pencarian sekaligus dalam satu iterasi**: mencari elemen **minimum dan maksimum** dalam bagian array yang belum terurut. Elemen minimum akan ditempatkan di awal, sedangkan elemen maksimum ditempatkan di akhir. Dengan cara ini, kita bisa menyortir dua elemen sekaligus dalam setiap iterasi, sehingga jumlah iterasi menjadi sekitar setengah dari selection sort biasa.

### Ilustrasi langkah:

Misal array: `[6, 3, 8, 1, 4, 7]`  
Ukuran `n = 6`

- Iterasi 1:
    - cari minimum (`1`) dan maksimum (`8`)
    - tempatkan `1` di depan, `8` di belakang → `[1, 3, 7, 6, 4, 8]`
- Iterasi 2:
    - cari minimum (`3`) dan maksimum (`7`) di tengah
    - tempatkan ke posisi sesuai → `[1, 3, 4, 6, 7, 8]`

### Implementasi C++:

```cpp
void bidirectionalSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIdx = left;
        int maxIdx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }

        // Tukar elemen minimum ke kiri
        swap(arr[left], arr[minIdx]);

        // Perlu cek jika posisi maksimum ikut berubah karena swap sebelumnya
        if (maxIdx == left) maxIdx = minIdx;

        // Tukar elemen maksimum ke kanan
        swap(arr[right], arr[maxIdx]);

        left++;
        right--;
    }
}
```

### Karakteristik:

- Kompleksitas waktu: tetap $O(n²)$, tetapi jumlah **iterasi utama berkurang separuh**.
- Lebih efisien dari selection sort biasa dalam praktik karena dua elemen ditangani dalam satu iterasi.
- Tidak stabil (bisa mengubah urutan elemen yang nilainya sama).
- Cocok untuk array kecil hingga menengah yang tidak terlalu besar.

## 4 | Stable Selection Sort

Selection Sort biasa **tidak stabil**, artinya urutan elemen yang bernilai sama bisa berubah. Kadang ini jadi masalah, terutama saat kita ingin mempertahankan urutan asli elemen yang nilainya sama (misalnya saat mengurutkan data mahasiswa berdasarkan nilai, tapi tetap ingin mempertahankan urutan absen).

Nah, **Stable Selection Sort** adalah versi yang **tidak menukar langsung**, tapi **menggeser** elemen-elemen yang berada di antara posisi elemen terkecil dan posisi saat ini, lalu menyisipkan elemen terkecil ke tempat yang benar.

### Contoh:

Array: `[(A, 4), (B, 5), (C, 4)]`  
Kita ingin menyortir berdasarkan angka, tapi menjaga urutan huruf jika angkanya sama.

- Pada Selection Sort biasa, `(C, 4)` bisa ditukar ke depan sehingga `(A, 4)` dan `(C, 4)` saling tukar posisi — ini **tidak stabil**.
    
- Pada versi stabil, `(C, 4)` tidak akan ditaruh di depan `(A, 4)` karena `(A, 4)` muncul lebih dulu.
    

### Implementasi C++:

```cpp
void stableSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        int key = arr[minIdx];

        // Geser elemen ke kanan
        while (minIdx > i) {
            arr[minIdx] = arr[minIdx - 1];
            minIdx--;
        }

        // Tempatkan elemen terkecil di posisi yang benar
        arr[i] = key;
    }
}
```

### Karakteristik:

- **Stabil**, karena tidak menukar sembarangan — elemen disisipkan dengan tetap mempertahankan urutan aslinya.
- Kompleksitas waktu tetap $O(n²)$.
- Lebih lambat sedikit dibanding selection sort biasa karena perlu operasi **geser (shift)**, bukan hanya tukar.
- Sangat berguna saat kestabilan sorting penting, seperti pada pengurutan data struktural.


## 5 | Recursive Selection Sort

Seperti namanya, **Recursive Selection Sort** adalah implementasi Selection Sort dengan pendekatan **rekursif**, bukan iteratif. Konsep dasarnya tetap sama: untuk setiap posisi `i`, kita cari elemen terkecil dari indeks `i` sampai akhir, lalu menukarnya dengan elemen di indeks `i`.

Bedanya, alih-alih menggunakan `for` loop, kita menyelesaikan sisa array dengan memanggil fungsi secara rekursif pada indeks berikutnya.

### Ilustrasi:

- Base case: jika indeks saat ini `i >= n-1`, berarti array sudah terurut.
    
- Step:
    
    - Cari indeks elemen minimum dari `i` sampai `n-1`.
        
    - Tukar elemen ke posisi `i`.
        
    - Panggil rekursi untuk `i+1`.
        

### Implementasi C++:

```cpp
int findMinIndex(int arr[], int start, int n) {
    int minIdx = start;
    for (int i = start + 1; i < n; ++i) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void recursiveSelectionSort(int arr[], int start, int n) {
    if (start >= n - 1) return;

    int minIdx = findMinIndex(arr, start, n);
    if (minIdx != start) {
        swap(arr[start], arr[minIdx]);
    }

    recursiveSelectionSort(arr, start + 1, n);
}
```

### Pemakaian di `main()`:

```cpp
int arr[] = {5, 3, 6, 2, 4};
int n = sizeof(arr) / sizeof(arr[0]);
recursiveSelectionSort(arr, 0, n);
```

### Karakteristik:

- Kompleksitas waktu: $O(n²)$ (karena tetap melakukan n kali pencarian minimum).
    
- Kompleksitas ruang: $O(n)$ untuk stack rekursi.
    
- Tidak efisien untuk array besar karena bisa menyebabkan **stack overflow**.
    
- Lebih sulit dipahami daripada versi iteratif, tetapi berguna untuk belajar konsep rekursi.
    
