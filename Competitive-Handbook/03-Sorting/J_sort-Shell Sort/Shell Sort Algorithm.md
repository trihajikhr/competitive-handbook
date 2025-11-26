---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STSS-0001
nama_algoritma: Shell Sort
kategori_algoritma: sorting
kesulitan: 🥈 medium
time_complexity: 🟤 O(n log n) > 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-18T20:51:00
tags:
  - sorting
  - array
  - shell-sort
---
#sorting #array #shell-sort

---
# Shell Sort Algorithm
Shell sort adalah versi umum dari algoritma insertion sort. Algoritma ini pertama-tama mengurutkan elemen-elemen yang berjauhan satu sama lain kemudian secara bertahap mengurangi interval antara elemen-elemen yang akan diurutkan.

Interval antara elemen-elemen dikurangi berdasarkan urutan yang digunakan. Beberapa urutan optimal yang dapat digunakan dalam algoritma shell sort adalah:

- **Urutan asli Shell**: N/2, N/4, ..., 1
- **Increment Knuth**: 1, 4, 13, ..., (3k – 1) / 2
- **Increment Sedgewick**: 1, 8, 23, 77, 281, 1073, 4193, 16577...4j+1+ 3·2j+ 1
- **Increment Hibbard**: 1, 3, 7, 15, 31, 63, 127, 255, 511...
- **Increment Papernov & Stasevich**: 1, 3, 5, 9, 17, 33, 65,...
- **Pratt**: 1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, 24, 36, 54, 81....

Catatan: Kinerja shell sort bergantung pada jenis urutan yang digunakan untuk array input tertentu.

> deepseek.com info


**Shell Sort** adalah versi umum dari algoritma **Insertion Sort**. Algoritma ini pertama-tama mengurutkan elemen-elemen yang berjauhan, kemudian secara bertahap mengurangi interval antara elemen-elemen yang akan diurutkan.

### Penjelasan Shell Sort:
1. **Prinsip Dasar**  
   - Shell Sort mengurutkan elemen dengan **interval tertentu** (gap), lalu memperkecil gap tersebut secara bertahap hingga mencapai 1 (pada titik ini, Shell Sort berperilaku seperti Insertion Sort biasa).  
   - Pendekatan ini memungkinkan pertukaran elemen-elemen yang berjauhan, sehingga mengurangi total perbandingan dan pertukaran yang dibutuhkan.

2. **Sequence (Deret Interval)**  
   - Performa Shell Sort sangat bergantung pada **jenis sequence** (deret interval) yang digunakan. Beberapa sequence yang umum dipakai:  

   | Nama Sequence             | Contoh Deret Interval                          |  
   |---------------------------|-----------------------------------------------|  
   | **Shell's original**       | `N/2, N/4, ..., 1`                            |  
   | **Knuth's increments**     | `1, 4, 13, ..., (3^k – 1) / 2`                |  
   | **Sedgewick's increments** | `1, 8, 23, 77, 281, 1073, 4193, 16577, ...`   |  
   | **Hibbard's increments**   | `1, 3, 7, 15, 31, 63, 127, 255, 511, ...`     |  
   | **Papernov & Stasevich**   | `1, 3, 5, 9, 17, 33, 65, ...`                 |  
   | **Pratt**                 | `1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, ...`    |  

   - **Catatan:** Pemilihan sequence memengaruhi efisiensi algoritma untuk suatu input tertentu.

### Keunggulan Shell Sort:
- **Lebih cepat** daripada Insertion Sort konvensional karena mengurangi total perbandingan elemen berjauhan.  
- **Kompleksitas waktu bervariasi** tergantung sequence, dengan kasus terbaik mencapai **O(n log n)**.  
- **In-place algorithm** (hanya membutuhkan ruang tambahan O(1)).  

### Contoh Analogi:  
Bayangkan mengurutkan tumpukan kartu dengan **pertama kali menyusun kartu yang terpisah jauh**, lalu secara bertahap memeriksa kartu yang lebih dekat hingga seluruhnya terurut.  
## Algoritma Shell Sort
1. Misalkan, kita perlu menyortir array berikut.
   
   ![[Shell Sort Algorithm-1.png]]
2. Kita menggunakan urutan asli Shell `(N/2, N/4, …, 1)` sebagai interval dalam algoritma kita. Dalam loop pertama, jika ukuran array adalah `N = 8` maka elemen-elemen yang berada pada interval `N/2 = 4` akan dibandingkan dan ditukar jika tidak dalam urutan yang benar.  
   - Elemen ke-`0` dibandingkan dengan elemen ke-`4`.  
   - Jika elemen ke-`0` lebih besar dari elemen ke-`4`, maka elemen ke-`4` terlebih dahulu disimpan dalam variabel `temp`, lalu elemen ke-`0` (yaitu elemen yang lebih besar) disimpan di posisi ke-`4`, dan elemen yang disimpan di `temp` disimpan di posisi ke-`0`.
     
      ![[Shell Sort Algorithm-2.png]]
    Proses ini berlanjut untuk semua elemen yang tersisa.  
    
    ![[Shell Sort Algorithm-3.png]]
3. Dalam loop kedua, interval sebesar `N/4 = 8/4 = 2` digunakan dan sekali lagi elemen-elemen yang berada pada interval ini disortir.
   
   ![[Shell Sort Algorithm-4.png]]
   Kamu mungkin akan merasa bingung pada titik ini.

   ![[Shell Sort Algorithm-5.png]]
   
   Elemen pada posisi ke-4 dan ke-2 dibandingkan. Elemen pada posisi ke-2 dan ke-0 juga dibandingkan. Semua elemen dalam array yang berada pada interval saat ini akan dibandingkan.
   
4. Proses yang sama berlanjut untuk elemen-elemen yang tersisa.
   
   ![[Shell Sort Algorithm-6.png]]
5. Akhirnya, ketika intervalnya adalah `N/8 = 8/8 = 1`, maka elemen-elemen array yang berada pada interval 1 disortir. Sekarang array telah tersortir sepenuhnya.
   
   ![[Shell Sort Algorithm-7.png]]


## Pseudocode Shell Sort
```bash
shellSort(array, size)
  for interval i <- size/2n down to 1
    for each interval "i" in array
        sort all the elements at interval "i"
end shellSort
```

# Contoh Algoritma Shell Sort
Dalam versi C++:

```cpp
// Shell Sort in C++ programming

#include <iostream>
using namespace std;

// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  cout << "Sorted array: \n";
  printArray(data, size);
}
```
# Shell Sort Complexity
## Time Complexity
Shell Sort adalah algoritma pengurutan yang merupakan pengembangan dari **Insertion Sort**. Algoritma ini meningkatkan efisiensi dengan membandingkan dan menukar elemen-elemen yang berjauhan terlebih dahulu sebelum membandingkan elemen-elemen yang berdekatan. Kompleksitas waktu Shell Sort bergantung pada **urutan gap (interval)** yang digunakan.
### Best Case (Kasus Terbaik) - $O(n\; log \; n)$
- **Kompleksitas:** **O(n log n)**
    
- **Kondisi:** Array sudah terurut sebagian atau sepenuhnya.
    
- **Penjelasan:** Jika array sudah hampir terurut, Shell Sort hanya memerlukan sedikit operasi perbandingan dan pertukaran. Beberapa urutan gap (seperti **Knuth's sequence**) dapat mencapai kompleksitas **O(n log n)** pada kasus terbaik.
### Average Case (Kasus Rata-rata) - $O(n \; log \; n)$ - $O(n^{3/2})$
- **Kompleksitas:** **O(n log n)** hingga **O(n^(3/2))** (tergantung urutan gap)
    
- **Penjelasan:**
    
    - Untuk urutan gap yang umum seperti **Hibbard's (2^k - 1)**, kompleksitas rata-ratanya adalah **O(n^(3/2))**.
        
    - Untuk urutan gap **Sedgewick's (1, 5, 19, 41, 109, ...)**, kompleksitas rata-ratanya mendekati **O(n^(4/3))**.
        
    - Jika menggunakan **Ciura's sequence**, kompleksitasnya bisa lebih baik.

### Worst Case (Kasus Terburuk) - $O(n^2)$
- **Kompleksitas:** **O(n²)**
    
- **Kondisi:** Array terurut terbalik (descending) dan urutan gap yang buruk digunakan (misalnya, urutan asli Shell: **n/2, n/4, ..., 1**).
    
- **Penjelasan:**
    
    - Jika gap sequence tidak optimal, Shell Sort bisa mendekati kompleksitas Insertion Sort (**O(n²)**).
        
    - Namun, dengan gap sequence yang lebih canggih (seperti Sedgewick atau Ciura), kompleksitas terburuk dapat ditingkatkan.
### Ringkasan
| Kasus        | Kompleksitas Waktu                |
| ------------ | --------------------------------- |
| Best Case    | $O(n\; log \; n)$                 |
| Average Case | $O(n \; log \; n)$ - $O(n^{3/2})$ |
| Worst Case   | $O(n^2)$                          |
## Space Complexity dan Stability
### Space Complexity
- **Kompleksitas:** **O(1)** (In-place sorting)
    
- **Penjelasan:**  
    Shell Sort adalah algoritma pengurutan **in-place**, artinya ia hanya menggunakan **ruang tambahan konstan** untuk variabel sementara (seperti `gap`, `temp`, dan indeks iterasi).
    
    - Tidak memerlukan struktur data eksternal seperti array atau list tambahan.
        
    - Cocok untuk lingkungan dengan memori terbatas.
### Stability
- **Shell Sort adalah algoritma pengurutan yang _tidak stabil_ (unstable).**
    
- **Penjelasan:**
    
    - Dalam Shell Sort, elemen-elemen yang bernilai sama bisa **bertukar posisi** karena pertukaran dilakukan berdasarkan **gap (interval)** yang besar terlebih dahulu.
        
    - Contoh:  
        Misalkan ada array `[5₁, 3, 5₂, 2]` (di mana `5₁` dan `5₂` adalah nilai 5 yang berbeda).  
        Jika `5₁` dan `5₂` dipindahkan dalam operasi pertukaran jarak jauh, urutan relatif mereka bisa berubah.  
        Hasil setelah pengurutan bisa menjadi `[2, 3, 5₂, 5₁]` (tidak mempertahankan urutan awal `5₁` sebelum `5₂`).

## Kesimpulan
| Faktor Complexity | Nilai                             |
| ----------------- | --------------------------------- |
| Best Case         | $O(n\; log \; n)$                 |
| Average Case      | $O(n \; log \; n)$ - $O(n^{3/2})$ |
| Worst Case        | $O(n^2)$                          |
| Space Complexity  | $O(1)$                            |
| Stability         | Unstable                          |
# Aplikasi Shell Sort
Shell sort digunakan dalam situasi di mana performa lebih baik dari insertion sort dibutuhkan, tetapi kompleksitas implementasi seperti merge sort atau quick sort tidak diinginkan. Beberapa aplikasi praktisnya antara lain:

- Menyortir array berukuran sedang di lingkungan dengan memori terbatas.
    
- Digunakan pada sistem embedded atau real-time di mana penggunaan stack atau rekursi tidak memungkinkan.
    
- Efektif untuk data yang sudah hampir tersortir.
    
- Digunakan dalam beberapa pustaka sorting klasik karena implementasinya yang sederhana namun efisien.
## Keunggulan dan kelemahan
### Keunggulan Shell Sort
- **Lebih cepat dari insertion sort dan bubble sort** untuk array besar.
    
- **In-place sorting**, tidak membutuhkan memori tambahan.
    
- **Tidak menggunakan rekursi**, sehingga cocok untuk sistem dengan batasan stack.
    
- Performa meningkat secara signifikan dengan urutan interval yang baik.
    
- **Mudah diimplementasikan** jika dibandingkan dengan algoritma divide and conquer seperti merge sort atau quick sort.
### Kelemahan Shell Sort
- **Kompleksitas waktu tidak konsisten**, tergantung pada urutan interval.
    
- **Kurang efisien dibandingkan merge sort dan quick sort** untuk data besar dengan urutan interval yang tidak optimal.
    
- **Tidak stabil**, artinya elemen dengan nilai sama bisa berubah urutan relatifnya setelah sorting.
    
- Tidak cocok untuk aplikasi di mana stabilitas penting (misalnya sorting berdasarkan dua kriteria).
## Kesimpulan
Shell sort merupakan algoritma sorting yang merupakan pengembangan dari insertion sort dengan ide menyortir elemen-elemen yang berjauhan terlebih dahulu. Meskipun tidak seefisien quick sort atau merge sort dalam kasus umum, Shell sort memiliki keunggulan dalam kesederhanaan implementasi, efisiensi ruang, dan performa yang baik untuk array berukuran sedang atau data yang hampir tersortir. Pemilihan urutan interval yang baik adalah kunci untuk memaksimalkan performa dari algoritma ini.