---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STHS-0001
nama_algoritma: Heap Sort
kategori_algoritma: sorting
kesulitan: 🥈 medium
time_complexity: 🟤 O(n log n)
memory_complexity: 🟢 O(1) ❌ → Unstable
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-18T09:32:00
tags:
  - sorting
  - array
  - heap-sort
---
#sorting #array #heap-sort

---
# Heap Sort Algorithm

**Heap Sort** adalah algoritma _sorting_ yang populer dan efisien dalam pemrograman komputer. Mempelajari cara menulis algoritma _heap sort_ memerlukan pengetahuan tentang dua jenis _data structure_ — _array_ dan _tree_.

Kumpulan awal angka yang ingin kita urutkan disimpan dalam sebuah _array_, misalnya `[10, 3, 76, 34, 23, 32]` dan setelah proses _sorting_, kita mendapatkan _array_ yang sudah diurutkan: `[3, 10, 23, 32, 34, 76]`.

_Heap sort_ bekerja dengan memvisualisasikan elemen-elemen dalam _array_ sebagai jenis khusus dari _complete binary tree_ yang disebut _heap_.

**Catatan**: Sebagai prasyarat, kamu harus mengetahui tentang _complete binary tree_ dan _heap data structure_.

## Relationship between Array Indexes and Tree Elements  
Sebuah _complete binary tree_ memiliki sifat menarik yang bisa kita manfaatkan untuk menemukan _children_ dan _parent_ dari setiap _node_.

Jika indeks dari suatu elemen dalam _array_ adalah `i`, maka elemen pada indeks `2i + 1` akan menjadi _left child_, dan elemen pada indeks `2i + 2` akan menjadi _right child_. Selain itu, _parent_ dari elemen manapun pada indeks `i` diberikan oleh nilai _lower bound_ dari `(i - 1) / 2`.

![[Heap Sort Algorithm-1.png]]

Ayo kita coba,

```bash
Left child dari 1 (indeks 0)
= elemen pada indeks (2×0 + 1)
= elemen pada indeks 1
= 12

Right child dari 1
= elemen pada indeks (2×0 + 2)
= elemen pada indeks 2
= 9

Demikian pula,

Left child dari 12 (indeks 1)
= elemen pada indeks (2×1 + 1)
= elemen pada indeks 3
= 5

Right child dari 12
= elemen pada indeks (2×1 + 2)
= elemen pada indeks 4
= 6
```

Mari kita juga konfirmasi bahwa aturan-aturan tersebut berlaku untuk menemukan _parent_ dari suatu _node_.

```bash
Parent dari 9 (posisi 2)
= (2 - 1) / 2
= ½
= 0.5
~ indeks 0
= 1

Parent dari 12 (posisi 1)
= (1 - 1) / 2
= indeks 0
= 1
```

Memahami pemetaan antara indeks _array_ dan posisi dalam _tree_ sangat penting untuk memahami bagaimana _Heap Data Structure_ bekerja dan bagaimana struktur tersebut digunakan untuk mengimplementasikan _Heap Sort_.
## Apa itu Heap Data Structure?  

_Heap_ adalah sebuah _data structure_ berbasis _tree_ yang khusus. Sebuah _binary tree_ dikatakan mengikuti _heap data structure_ jika:

1. Itu adalah _complete binary tree_.
    
2. Semua _node_ dalam _tree_ mengikuti sifat bahwa mereka lebih besar dari _children_ mereka, yaitu elemen terbesar berada di _root_, dan kedua _children_nya lebih kecil dari _root_, dan seterusnya. _Heap_ seperti ini disebut _max-heap_. Jika sebaliknya, semua _node_ lebih kecil dari _children_ mereka, maka disebut _min-heap_.
    

Diagram contoh berikut menunjukkan _Max-Heap_ dan _Min-Heap_.

![[Heap Sort Algorithm-2.png]]

## Cara "heapify" pada sebuah tree
Memulai dari sebuah _complete binary tree_, kita dapat memodifikasinya untuk menjadi _Max-Heap_ dengan menjalankan fungsi yang disebut _heapify_ pada semua elemen yang bukan _leaf_ dalam _heap_.

Karena _heapify_ menggunakan rekursi, hal ini bisa sulit dipahami. Jadi, mari kita pikirkan terlebih dahulu bagaimana cara _heapify_ pada sebuah _tree_ dengan hanya tiga elemen.

```cpp
heapify(array)
    Root = array[0]
    Largest = largest( array[0], array[2*0 + 1], array[2*0+2] )
    if(Root != Largest)
          Swap(Root, Largest)
```

![[Heap Sort Algorithm-3.png]]

Contoh di atas menunjukkan dua skenario - satu di mana root adalah elemen terbesar dan kita tidak perlu melakukan apa-apa. Dan satu lagi di mana root memiliki elemen yang lebih besar sebagai _child_ dan kita perlu melakukan _swap_ untuk mempertahankan properti _max-heap_.

Jika kamu sudah pernah bekerja dengan algoritma rekursif sebelumnya, kamu mungkin sudah mengidentifikasi bahwa ini adalah kasus dasar.

Sekarang mari kita pikirkan skenario lain di mana ada lebih dari satu level.

![[Heap Sort Algorithm-4.png]]

Elemen teratas bukanlah _max-heap_ tetapi semua _sub-tree_ adalah _max-heap_.

Untuk mempertahankan properti _max-heap_ pada seluruh _tree_, kita harus terus mendorong elemen ke bawah hingga mencapai posisi yang benar.

![[Heap Sort Algorithm-5.png]]

Dengan demikian, untuk mempertahankan properti _max-heap_ dalam sebuah _tree_ di mana kedua _sub-tree_ adalah _max-heap_, kita perlu menjalankan _heapify_ pada elemen root berulang kali hingga elemen tersebut lebih besar dari _children_-nya atau menjadi _leaf node_.

Kita dapat menggabungkan kedua kondisi ini dalam satu fungsi _heapify_ sebagai berikut:

```cpp
void heapify(int arr[], int n, int i) {
  // Temukan yang terbesar di antara root, left child, dan right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Tukar dan lanjutkan heapify jika root bukan yang terbesar
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}
```

Fungsi ini bekerja untuk kedua kasus dasar dan untuk _tree_ dengan ukuran apapun. Dengan demikian, kita dapat memindahkan elemen root ke posisi yang benar untuk mempertahankan status _max-heap_ untuk ukuran _tree_ apapun selama _sub-tree_ nya adalah _max-heap_.
## Bangun max-heap  
Untuk membangun _max-heap_ dari _tree_ apapun, kita bisa mulai dengan _heapifying_ setiap _sub-tree_ dari bawah ke atas dan akhirnya mendapatkan _max-heap_ setelah fungsi diterapkan pada semua elemen termasuk elemen root.

Dalam kasus _complete tree_, indeks pertama dari _non-leaf node_ diberikan oleh `n / 2 - 1`. Semua _node_ lainnya setelah itu adalah _leaf node_ dan oleh karena itu tidak perlu di-_heapify_.

Jadi, kita bisa membangun _max-heap_ sebagai berikut:

```cpp
// Bangun heap (susun ulang array)
for (int i = n / 2 - 1; i >= 0; i--)
  heapify(arr, n, i);
```

![[Heap Sort Algorithm-6.png]]

![[Heap Sort Algorithm-7.png]]

![[Heap Sort Algorithm-8.png]]

![[build-max-heap-2_01 edit.png]]

Seperti yang ditunjukkan pada diagram di atas, kita mulai dengan _heapifying_ _sub-tree_ terkecil yang paling bawah dan secara bertahap bergerak ke atas hingga mencapai elemen root.

Jika kamu sudah memahami semuanya sampai di sini, selamat, kamu sedang dalam perjalanan untuk menguasai _Heap Sort_.
## Algoritma Heap Sort

1. Karena _tree_ memenuhi properti _Max-Heap_, maka elemen terbesar disimpan di _root node_.  
2. **Tukar:** Hapus elemen root dan letakkan di akhir array (posisi ke-n). Letakkan elemen terakhir dari _tree_ (_heap_) pada tempat yang kosong.  
3. **Hapus:** Kurangi ukuran _heap_ sebesar 1.  
4. **Heapify:** Lakukan _heapify_ pada elemen root lagi agar elemen tertinggi berada di root.  
5. Proses ini diulang hingga semua elemen dalam daftar terurut.

![[heap_sort.png]]

Kode di bawah ini menunjukkan operasinya:

```cpp
// Heap sort
for (int i = n - 1; i >= 0; i--) {
  swap(&arr[0], &arr[i]);

  // Heapify elemen root untuk mendapatkan elemen tertinggi di root lagi
  heapify(arr, i, 0);
}
```

Atau:

```cpp
void heapSort(int arr[], int n) {
  // Bangun max-heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Ambil elemen dari heap satu per satu
  for (int i = n - 1; i > 0; i--) {
    // Pindahkan elemen root ke akhir
    swap(&arr[0], &arr[i]);

    // Heapify elemen root yang baru
    heapify(arr, i, 0);
  }
}
```
# Contoh Algoritma Heap Sort

```cpp
// Heap Sort dalam C++

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  // Temukan yang terbesar di antara root, left child, dan right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Tukar dan lanjutkan heapifying jika root bukan yang terbesar
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// Fungsi utama untuk melakukan heap sort
void heapSort(int arr[], int n) {
  // Bangun max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify elemen root untuk mendapatkan elemen tertinggi di root lagi
    heapify(arr, i, 0);
  }
}

// Mencetak array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

// Kode driver
int main() {
  int arr[] = {1, 12, 9, 5, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  heapSort(arr, n);

  cout << "Array yang sudah diurutkan adalah \n";
  printArray(arr, n);
}
```
# Heap Sort Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - $O(n \;log\; n)$
Heap Sort memiliki waktu yang sama pada semua kasus, karena selalu perlu membangun heap dan melakukan heapify pada setiap elemen, meskipun array sudah terurut.
### Average Case (Kasus Rata-rata) - $O(n \;log\; n)$
Kompleksitas waktu rata-rata Heap Sort adalah O(n log n). Hal ini karena setiap operasi heapify memerlukan waktu O(log n), dan kita memanggil heapify untuk setiap elemen.

### Worst Case (Kasus Terburuk) - $O(n \;log\; n)$
Kompleksitas waktu terburuk untuk Heap Sort adalah O(n log n), yang terjadi ketika kita perlu melakukan operasi heapify pada seluruh array.
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n \;log\; n)$   |
| Average Case | $O(n \;log\; n)$   |
| Worst Case   | $O(n \;log\; n)$   |
## Space Complexity dan Stability
### Space Complexity
Kompleksitas ruang Heap Sort adalah O(1) karena hanya membutuhkan ruang konstan untuk operasi swap dan heapify, tidak memerlukan ruang tambahan selain array input.
### Stability
Heap Sort **tidak stabil**. Artinya, elemen-elemen dengan nilai yang sama mungkin tidak mempertahankan urutan relatif mereka setelah pengurutan.

## Kesimpulan
| Faktor Complexity | Nilai            |
| ----------------- | ---------------- |
| Best Case         | $O(n \;log\; n)$ |
| Average Case      | $O(n \;log\; n)$ |
| Worst Case        | $O(n \;log\; n)$ |
| Space Complexity  | $O(1)$           |
| Stability         | Unstable         |
## Programmiz Info

**Heap Sort memiliki kompleksitas waktu O(n log n) untuk semua kasus (kasus terbaik, kasus rata-rata, dan kasus terburuk).**

Mari kita pahami alasannya:

1. **Struktur Pohon Biner**  
   Tinggi dari sebuah pohon biner lengkap yang berisi *n* elemen adalah **log n**.

2. **Proses Heapify**  
   Seperti yang telah kita lihat sebelumnya, untuk melakukan *heapify* pada sebuah elemen yang sub-pohonnya sudah berupa *max-heap*, kita perlu terus membandingkan elemen tersebut dengan anak kiri dan kanannya serta menurunkannya hingga mencapai posisi di mana kedua anaknya lebih kecil darinya.  

   - **Kasus Terburuk**  
     Dalam skenario terburuk, kita mungkin perlu memindahkan elemen dari akar ke daun, yang membutuhkan sekitar **log n** perbandingan dan pertukaran.

3. **Tahap Build Max-Heap**  
   Pada tahap *build_max_heap*, proses ini dilakukan untuk **n/2** elemen, sehingga kompleksitas kasus terburuknya adalah:  
   ```
   n/2 * log n ≈ n log n
   ```

4. **Tahap Pengurutan (Heap Sort)**  
   Pada tahap pengurutan:  
   - Kita menukar elemen akar dengan elemen terakhir, lalu melakukan *heapify* pada elemen akar.  
   - Untuk setiap elemen, proses ini membutuhkan waktu **log n** (kasus terburuk), karena kita mungkin harus membawa elemen dari akar hingga daun.  
   - Karena ini diulang **n** kali, kompleksitas tahap *heap_sort* juga **n log n**.  

5. **Total Kompleksitas**  
   Karena *build_max_heap* dan *heap_sort* dijalankan secara berurutan, kompleksitas algoritmiknya tidak dikalikan, melainkan tetap **O(n log n)**.

6. **Kompleksitas Ruang**  
   Algoritma ini melakukan pengurutan dengan kompleksitas ruang **O(1)** (tanpa membutuhkan ruang tambahan yang signifikan).

7. **Perbandingan dengan Quick Sort**  
   - **Heap Sort** memiliki kasus terburuk yang lebih baik (**O(n log n)**) dibandingkan **Quick Sort** yang memiliki kompleksitas **O(n²)** dalam kasus terburuk.  
   - Namun, dalam kasus lainnya, **Quick Sort** lebih cepat.  
   - **Introsort** adalah alternatif pengurutan yang menggabungkan **Quick Sort** dan **Heap Sort** untuk mempertahankan keunggulan keduanya:  
     - Kecepatan kasus terburuk dari **Heap Sort**.  
     - Kecepatan rata-rata dari **Quick Sort**.  

# Aplikasi Heap Sort

**Sistem yang berkaitan dengan keamanan dan sistem tertanam (seperti Linux Kernel) menggunakan Heap Sort karena batas atas waktu eksekusinya O(n log n) dan penggunaan penyimpanan tambahan yang konstan O(1).**  

Meskipun **Heap Sort** memiliki kompleksitas waktu **O(n log n)** bahkan dalam kasus terburuk, algoritma ini tidak banyak digunakan (dibandingkan dengan algoritma pengurutan lain seperti **Quick Sort** atau **Merge Sort**). Namun, struktur data dasarnya, yaitu **heap**, dapat dimanfaatkan secara efisien jika kita ingin mengekstrak elemen terkecil (atau terbesar) dari daftar tanpa perlu menjaga urutan sisa elemennya.  

**Contoh Penggunaan:**  
- **Priority Queues (Antrian Berprioritas)**  

---

### Penjelasan Lebih Rinci:  
1. **Penggunaan dalam Sistem Keamanan & Embedded**  
   - Heap Sort dipilih karena **efisiensi waktu terjamin (O(n log n))** dan **efisiensi memori (O(1))**, sehingga cocok untuk sistem yang membutuhkan prediktabilitas tinggi seperti kernel OS atau perangkat dengan sumber daya terbatas.  

2. **Keterbatasan Heap Sort**  
   - Meskipun cepat dalam semua kasus, Heap Sort **kalah populer dibanding Quick Sort atau Merge Sort** karena:  
     - **Faktor konstannya lebih besar** (lebih lambat dalam praktek meski kompleksitas sama).  
     - **Tidak stabil** (tidak mempertahankan urutan relatif elemen yang sama).  

3. **Kelebihan Struktur Heap**  
   - Struktur **heap** tetap berguna untuk aplikasi yang memerlukan akses cepat ke elemen prioritas tertinggi/terendah, seperti:  
     - **Antrian prioritas** (misalnya: penjadwalan tugas, algoritma Dijkstra).  
     - **Alokasi memori dinamis** (contoh: manajemen heap dalam pemrograman sistem).  

## Keunggulan dan kelemahan
### Keunggulan Heap Sort
- Heap Sort memiliki kompleksitas waktu yang konsisten O(n log n), baik pada kasus terbaik, rata-rata, atau terburuk.
    
- Memiliki ruang tambahan yang sangat rendah, yaitu O(1), menjadikannya pilihan baik untuk ruang terbatas.
### Kelemahan Heap Sort
- Heap Sort tidak stabil, yang berarti elemen dengan nilai yang sama bisa berubah urutannya.
    
- Implementasinya lebih rumit dibandingkan dengan algoritma lain seperti Merge Sort atau Quick Sort.
## Kesimpulan
Heap Sort adalah algoritma pengurutan yang efisien dalam hal waktu, dengan kompleksitas O(n log n), dan memiliki keuntungan dalam ruang yang sangat rendah. Namun, algoritma ini tidak stabil dan lebih sulit diimplementasikan dibandingkan dengan algoritma pengurutan lainnya.