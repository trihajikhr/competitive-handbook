---
obsidianUIMode: preview
note_type: book theory
judul_materi: Hint Iterator pada Multiset
sumber:
  - myself
date_learned: 2026-07-27T22:40:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Hint Iterator pada Multiset

Ketika kita ingin memasukkan elemen baru ke dalam `std::multiset` dan kita sudah memiliki perkiraan posisi atau *iterator* yang mendekati lokasi penempatan elemen tersebut (misalnya elemen baru bernilai mirip atau berurutan dengan elemen sebelumnya), kita bisa menggunakan fungsi `insert(hint_iterator, value)` atau `emplace_hint()`.

Jika *hint* yang diberikan tepat atau berada sangat dekat dengan posisi aslinya di dalam *tree*, waktu penyisipan dapat dipercepat mendekati $O(1)$ *amortized* karena pustaka tidak perlu melakukan penelusuran dari *root*.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka = {10, 20, 30};

    // Menggunakan elemen terakhir sebagai hint karena nilai yang dimasukkan lebih besar
    auto hint = angka.end();
    --hint; 

    // Memasukkan angka 40 dengan bantuan hint agar pencarian posisi lebih cepat
    angka.insert(hint, 40);

    std::cout << "Isi multiset:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Mengapa ini Bekerja?

Bagian ini membahas secara komprehensif landasan kerja dan alasan mengapa penggunaan *hint iterator* pada fungsi `insert()` atau `emplace_hint()` dapat mempercepat proses penyisipan elemen ke dalam `std::multiset`.

### 1. Mekanisme Dasar Penyisipan pada *Binary Search Tree*

Secara default, ketika kita memanggil fungsi `angka.insert(value)` tanpa memberikan petunjuk posisi, struktur internal `std::multiset` (yang berupa *self-balancing binary search tree*) harus melakukan penelusuran (*traversal*) dari simpul *root* untuk mencari posisi yang tepat bagi elemen baru sesuai dengan aturan pengurutan. Proses penelusuran *root* ini memakan waktu sebesar $O(\log N)$.

### 2. Peran *Hint Iterator* sebagai Titik Awal

Ketika kita menyediakan argumen tambahan berupa *hint iterator* melalui `angka.insert(hint, value)` atau `angka.emplace_hint(hint, value)`, kita memberikan titik referensi atau perkiraan lokasi di mana elemen tersebut seharusnya ditempatkan.

* Pustaka standar C++ menggunakan *hint* tersebut untuk memeriksa apakah elemen baru dapat disisipkan tepat di sebelah posisi *hint* (misalnya jika nilainya berurutan atau bernilai mirip).
* Jika *hint* yang diberikan akurat—seperti ketika elemen baru bernilai lebih besar dan *hint* menunjuk ke elemen terakhir via `angka.end()`—struktur pohon dapat langsung menempatkan elemen baru di dekat posisi tersebut tanpa harus menelusuri ulang dari *root*.

### 3. Kompleksitas Waktu Amortisasi Menjadi $O(1)$

Jika posisi *hint* yang diberikan tepat atau berada sangat dekat dengan lokasi penempatan yang benar di dalam pohon:

* Waktu pencarian posisi dapat dipangkas secara signifikan dari yang tadinya membutuhkan penelusuran penuh berwaktu $O(\log N)$ menjadi mendekati $O(1)$ secara amortisasi.
* Meskipun penyeimbangan ulang pohon (*rebalancing*) tetap dapat terjadi di latar belakang untuk menjaga properti *self-balancing*, efisiensi pencarian posisi awal memberikan peningkatan performa yang sangat terasa dalam pemrosesan data berjumlah masif pada pemrograman kompetitif.

### 4. Contoh Analisis Implementasi

Perhatikan cuplikan kode berikut:

```cpp
auto hint = angka.end();
--hint; 
angka.insert(hint, 40);
```

Variabel `hint` diatur untuk menunjuk ke elemen terakhir dari `std::multiset`. Karena nilai `40` yang ingin dimasukkan bernilai lebih besar dari elemen-elemen sebelumnya, posisi penyisipannya sudah pasti berada di dekat atau tepat setelah *hint* tersebut. Dengan demikian, pustaka dapat langsung meletakkan elemen baru secara efisien tanpa pencarian dari *root*.