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

==Source: programiz.com==
Pencarian linear adalah algoritma pencarian secara berurutan di mana kita mulai dari salah satu ujung dan memeriksa setiap elemen dalam daftar sampai elemen yang diinginkan ditemukan. Ini adalah algoritma pencarian yang paling sederhana.

==Source: chatGpt==
“Pencarian linear” (atau _sequential search_) adalah metode paling dasar untuk mencari sebuah nilai di dalam sekumpulan data (misalnya di dalam array atau list). Secara garis besar, mekanismenya adalah sebagai berikut:

1. **Mulai dari salah satu ujung struktur data**  
    Biasanya kita memulai dari indeks pertama (indeks 0) pada array, tetapi bisa juga dari indeks terakhir—prinsipnya sama, yaitu bergerak secara berurutan.
<br/>

2. **Periksa setiap elemen satu per satu**  
    Pada iterasi pertama, kita membandingkan nilai elemen pertama dengan nilai target yang ingin dicari. Jika belum sama, kita lanjutkan ke elemen kedua, lalu ketiga, dan seterusnya. Setiap kali kita mengunjungi sebuah elemen, kita melakukan satu operasi perbandingan: “Apakah `elemen[i] == target`?”
<br/>

3. **Berhenti saat target ditemukan**  
    Ketika suatu elemen sama dengan nilai target, kita segera menghentikan pencarian dan biasanya mengembalikan posisi (indeks) elemen itu. Pada titik ini, algoritma selesai, tanpa perlu melihat sisa elemen di belakangnya.
<br/>

4. **Apabila sudah mencapai ujung tanpa menemukannya**  
    Jika setelah memeriksa semua elemen (dari indeks 0 hingga indeks terakhir) belum ada yang cocok dengan target, maka kita dapat menyimpulkan bahwa nilai tersebut tidak ada di dalam array. Biasanya, algoritma pun mengembalikan nilai khusus (misalnya `-1`) untuk menandakan “tidak ditemukan.”
    

Dengan cara ini, pencarian linear tidak melakukan “pelompatan” atau “pemangkasan” apapun—setiap elemen diperiksa satu per satu hingga kondisi berhenti terpenuhi. Karena inilah algoritma ini disebut “linear”: jumlah langkah (perbandingan) yang dijalankan pada kasus terburuk berbanding lurus dengan jumlah elemen $n$.
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

Linear Search melakukan pemeriksaan satu per satu pada setiap elemen dalam sebuah array atau list hingga menemukan elemen yang dicari atau hingga seluruh elemen habis diperiksa. Karena prosesnya bersifat sekuensial tanpa ada pemangkasan (pruning), maka kompleksitas waktu untuk Linear Search dapat dijabarkan sebagai berikut:

1. **Best Case (Θ(1))**
    
    - Kasus terbaik terjadi apabila elemen yang dicari berada di indeks pertama (indeks 0).
        
    - Hanya satu perbandingan yang dilakukan: `arr[0] == target`.
        
    - Notasi asymptotic:
        
        $$\Theta(1)$$
        
        Artinya, waktu eksekusi konstan tidak bergantung pada ukuran nn.
        
2. **Average Case (Θ(n))**
    
    - Diasumsikan posisi elemen yang dicari acak dan tersebar merata dari awal hingga akhir array.
        
    - Secara rata-rata, Linear Search akan memeriksa sekitar $\frac{n}{2}$ elemen sebelum menemukan target, jika target memang ada di dalam array.
        
    - Namun dalam notasi Θ kita mengabaikan konstanta $\frac{1}{2}$, sehingga menjadi:
        
        $$ \Theta(n)$$
3. **Worst Case (O(n))**
    
    - Kasus terburuk terjadi apabila elemen yang dicari tidak ada dalam array, atau berada di indeks terakhir (indeks $n - 1$).
        
    - Linear Search harus memeriksa semua elemen satu per satu—total $n$ perbandingan.
        
    - Notasi Big-O:
        
        $$O(n)$$
        
        karena pertumbuhan jumlah perbandingan berbanding lurus dengan ukuran data $n$.
        

Secara ringkas, walaupun pada kasus terbaik Linear Search hanya memerlukan $\Theta(1)$, namun karena skenario rata-rata dan terburuknya bersifat linear terhadap $n$, umumnya kita menyatakan kompleksitas waktu Linear Search sebagai **O(n)**.

---

## Space Complexity

Linear Search hampir tidak memerlukan memori tambahan yang signifikan—hanya memanfaatkan satu atau dua variabel sementara (misalnya, variabel indeks `i` dan variabel penanda `target` jika perlu). Jadi:

- **Kompleksitas ruang (Space Complexity):**
    
    $$O(1)$$
    
    (Konstan)  
    Karena menggunakan jumlah memori tetap terlepas dari berapa banyak elemen $n$ dalam array.
    

---

# Aplikasi Linear Search

Meskipun Linear Search bukan yang paling cepat untuk dataset besar, terdapat beberapa situasi atau kasus di mana Linear Search justru masih layak dipakai:

1. **Array/List Berukuran Kecil**
    
    - Jika jumlah elemen $n$ relatif sangat kecil (misalnya $n < 100$ atau bahkan $n < 1000$), overhead algoritma linear (yang hanya melakukan satu loop sederhana) bisa lebih murah daripada algoritma pencarian yang lebih kompleks (seperti Binary Search) karena tidak perlu preprocessing (misal: sortir array).
        
    - Contoh:
        
        ```cpp
        int linearSearch(int arr[], int n, int x) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == x) return i;
            }
            return -1;
        }
        ```
        
    - Pada array berukuran kecil, perbedaan antara $O(n)$ dan $O(\log n)$ mungkin tidak terasa signifikan, terutama jika data tidak terurut.
        
2. **Data Belum Terurut (Unsorted)**
    
    - Linear Search dapat langsung dijalankan pada daftar yang belum diurutkan tanpa langkah tambahan.
        
    - Jika kita mengetahui tidak akan ada banyak elemen, menyortir dahulu untuk kemudian melakukan Binary Search justru bisa memperburuk performa (karena kost sorting $O(n \log n)$ vs hanya $O(n)$ sekali jalan).
        
3. **Koleksi Dinamis Tanpa Indeksasi Langsung (Linked List, dll.)**
    
    - Pada struktur data seperti Linked List, Random Access tidak tersedia. Untuk menjalankan Binary Search, kita membutuhkan akses ke elemen tengah secara langsung—hal ini tidak praktis pada Linked List tanpa langkah ekstra (seperti menghitung panjang dan menavigasi ke tengah). Linear Search (traversal sekuensial) adalah cara paling sederhana untuk menemukan nilai tertentu di Linked List.
        
4. **Pemrosesan Satu Kali atau Jumlah Pencarian Terbatas**
    
    - Jika program hanya membutuhkan satu atau dua kali pencarian pada dataset, overhead membangun struktur data bantu (hash table, tree, DLL terurut, dll.) tidak sebanding dengan keuntungan skor performa. Linear Search sekali atau dua kali tetap lebih cepat dalam asumsi implementasinya ringan.
        
5. **Implementasi Sederhana pada Profiling atau Debugging**
    
    - Kadang, saat debugging atau memprofil program, kita butuh cara cepat untuk memeriksa apakah sebuah nilai terdapat di dalam array. Linear Search mudah ditulis dan diverifikasi, sehingga cocok digunakan pada prototyping sebelum dioptimasi di kemudian hari.
        

---

## Keunggulan dan Kelemahan

### Keunggulan Linear Search

1. **Implementasi Sederhana**
    
    - Hanya membutuhkan loop tunggal dan satu perbandingan per iterasi.
        
    - Tidak ada langkah-langkah tambahan seperti pemrosesan ulang data (sorting, indexing).
        
2. **Tidak Memerlukan Data Terurut**
    
    - Linear Search dapat dijalankan langsung pada array yang belum diurutkan, sehingga menghemat waktu jika tidak ada jaminan bahwa data sudah terurut sebelumnya.
        
3. **Konstanta Ruang Kecil (O(1))**
    
    - Hanya memerlukan beberapa variabel tambahan (biasanya hanya indeks dan variabel penyimpan nilai target).
        
    - Tidak perlu membuat array pendukung, struktur hash, atau rekursi yang dalam.
        
4. **Efisien untuk Koleksi Kecil**
    
    - Jika $n$ kecil (misalnya < 100), Linear Search biasanya sudah cukup cepat dalam praktik, karena overhead algoritma yang lebih rumit (semisal membangun heap atau sorted list) justru lebih besar.
        
5. **Cocok untuk Struktur Dinamis Non-Indeks (Linked List)**
    
    - Pada Linked List, kita tidak punya akses acak (random access). Linear Search (iterasi satu per satu) adalah satu-satunya cara sederhana untuk menemukan node dengan nilai tertentu—tanpa perlu membangun struktur tambahan.
        
6. **Konsisten pada Semua Kasus (Deterministik)**
    
    - Waktu eksekusi tergantung secara linier pada ukuran array, sehingga mudah diprediksi.
        

### Kelemahan Linear Search

1. **Tidak Skalabel untuk Dataset Besar**
    
    - Jika $n$ sangat besar (ribuan, jutaan, atau lebih), memeriksa setiap elemen satu per satu menjadi sangat tidak efisien — memakan waktu panjang, terutama jika banyak pencarian yang dijalankan secara berulang.
        
2. **Tidak Memanfaatkan Struktur Data Terurut**
    
    - Saat data sudah terurut, kita bisa menggunakan Binary Search dengan kompleksitas $O(\log n)$. Menggunakan Linear Search di data terurut “membuang” keuntungan urutan tersebut.
        
3. **Perbandingan Redundan**
    
    - Bahkan jika target berada di akhir array, Linear Search akan tetap mengecek semua elemen dari awal hingga akhir. Ini berarti jumlah perbandingan bisa sangat besar sebelum berhenti di kasus terburuk.
        
4. **Kurang Efisien saat Banyak Pencarian Berulang**
    
    - Jika dalam satu program kita melakukan banyak kali pencarian di array yang sama, lebih baik menginvestasikan waktu untuk membangun struktur indeks (misal: hash table atau binary-search tree) agar keseluruhan pencarian jadi lebih cepat (amortized cost lebih rendah).
        
5. **Tidak Ada Short-Circuit atau Pruning**
    
    - Berbeda dengan algoritma pencarian pada pohon terurut (seperti Binary Search Tree atau B-Tree), Linear Search tidak pernah “melompat” ke sekian posisi atau mengabaikan sebagian besar data. Ia harus memeriksa semua hingga target ditemukan atau data habis.
        

---

## Contoh Ilustrasi Pseudocode yang Lebih Lengkap

```cpp
// Fungsi Linear Search pada array integer
// Mengembalikan indeks elemen pertama yang sama dengan target, atau -1 jika tidak ditemukan.
int linearSearch(int arr[], int n, int target) {
    // Iterasi dari indeks 0 hingga n-1
    for (int i = 0; i < n; i++) {
        // Setiap elemen dibandingkan dengan target
        if (arr[i] == target) {
            return i; // Kembalikan indeks jika ditemukan
        }
    }
    // Jika loop selesai tanpa return, berarti target tidak ada di dalam array
    return -1;
}

/*
Penjelasan langkah demi langkah:
1. Mulai i = 0.
2. Bandingkan arr[0] dengan target.
   - Jika sama, langsung return 0 → Best Case (Θ(1)).
3. Jika tidak sama, lanjutkan i = 1, bandingkan arr[1] vs target.
4. Ulangi hingga i = n-1.
5. Jika pada i = n-1 masih tidak cocok, berarti target tidak ada; return -1 → Worst Case (O(n)).
   Jika target ada di posisi terakhir, kita melakukan n perbandingan.
6. Rata-rata (Average Case) kita akan berhenti di sekitar i = n/2, yakni Θ(n).
*/
```

Selain array, kita juga bisa melakukan Linear Search pada struktur data lain, misalnya:

- **Linked List**: Travelling node demi node karena tidak ada random access.
    
- **Vector (di C++ STL)**: Mirip array dinamis, indeksa berjalan sekuensial.
    
- **String (pencarian karakter)**: Jika kita ingin mencari satu karakter tertentu, kita dapat iterasi setiap karakter—ini pada dasarnya Linear Search di array of char.
    

---

## Keputusan Menggunakan Linear Search

Secara ringkas, pemilihan Linear Search cocok jika:

1. **Ukuran Data Kecil** ($n$ relatif kecil, misalnya < 100 atau < 1000).
    
2. **Data Tidak Terurut** dan tidak layak untuk disort atau dibangun indeksnya.
    
3. **Hanya Satu atau Beberapa Pencarian** di satu program, sehingga overhead preprocessing tidak sepadan dengan waktu pencarian tunggal.
    
4. **Struktur Data Tidak Mendukung Random Access** (Linked List, array in a disk file yang harus dibaca sekuensial).
    
5. **Implementasi Cepat untuk Prototipe atau Debugging**, di mana kejelasan kode lebih diutamakan daripada performa maksimal.
    

Jika salah satu kondisi di atas terpenuhi, Linear Search sering kali menjadi pilihan yang logis. Namun, jika:

- **Dataset Besar** (ribuan, jutaan elemen),
    
- **Banyak Pencarian Berulang**,
    
- **Data Sudah Terurut**,  
    – maka lebih baik mempertimbangkan algoritma pencarian lain (Binary Search, Hash Table Lookup, Jump Search, Fibonacci Search, dsb.) yang memiliki kompleksitas lebih baik (misalnya $O(\log n)$ atau bahkan $O(1)$ rata-rata).
    

---

## Kesimpulan

- **Complexity:**
    
    - **Time Complexity:**
        
        - Best Case: $\Theta(1)$
            
        - Average Case: $\Theta(n)$
            
        - Worst Case: $O(n)$
            
    - **Space Complexity:** $O(1)$ (konstan).
        
- **Kelebihan Linear Search:**
    
    - Implementasi sangat sederhana.
        
    - Tidak memerlukan data terurut.
        
    - Memori tambahan minimal (konstan).
        
    - Bagus untuk dataset kecil atau ketika hanya perlu satu-dua kali pencarian saja.
        
    - Cocok untuk struktur data tanpa random access (misalnya Linked List).
        
- **Kekurangan Linear Search:**
    
    - Tidak efisien untuk dataset besar (waktu eksekusi linear terhadap jumlah elemen).
        
    - Tidak memanfaatkan urutan data bila sudah tersedia.
        
    - Tidak optimal jika pencarian dilakukan berkali-kali pada data yang sama.
        
    - Selalu memeriksa satu per satu hingga akhir, sehingga banyak perbandingan redundant jika target ada jauh di belakang.
        

Dengan memahami secara detail kasus terbaik, rata-rata, dan terburuk Linear Search, serta karakteristik struktur data dan situasi penggunaannya, Anda dapat memutuskan kapan Linear Search cukup memadai—dan kapan saatnya beralih pada algoritma pencarian yang lebih cepat.