---
obsidianUIMode: preview
note_type: book theory
judul_materi: Membangun Multiset dengan Efisien
sumber:
  - myself
date_learned: 2026-07-27T22:30:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Membangun Multiset dengan Efisien

Memasukkan elemen satu per satu ke dalam `std::multiset` melalui fungsi `insert()` secara berulang akan memakan waktu $O(N \log N)$ dengan overhead konstan yang cukup besar karena *tree* harus terus-menerus menyeimbangkan diri dan mengalokasikan memori *node* baru pada setiap penyisipan.

```cpp
// terlalu lambat secara kompleksitas!
std::multiset<int> angka;

for(int i=0, x; i<n; i++) {
	cin >> x;
	angka.insert(x);
}
```

Sebaliknya, jika kita menampung seluruh elemen terlebih dahulu di dalam wadah sekuensial seperti `std::vector` (yang pengisian elemen awalnya sangat cepat karena *contiguous memory* dan *append* berbiaya $O(1)$ *amortized*), lalu kita melakukan *range construction* pada `std::multiset`, misalnya

```cpp
std::multiset<int> angka(vec.begin(), vec.end());
```

, maka algoritma internal pustaka standar dapat mengoptimalkan proses pembentukan *tree* tersebut, atau setidaknya meminimalisasi kompleksitas overhead penyisipan berulang secara signifikan.

## Membangun *Multiset* Melalui *Range Constructor*

Saat kita perlu memasukkan sejumlah besar $N$ elemen ke dalam `std::multiset`, melakukan penyisipan satu per satu menggunakan fungsi `insert()` secara berulang sering kali kurang efisien akibat *overhead* penyeimbangan *balanced binary search tree* yang berulang-ulang pada setiap penambahan elemen.

Cara yang jauh lebih efisien adalah dengan menampung seluruh elemen terlebih dahulu ke dalam wadah sekuensial seperti `std::vector`, lalu menginisialisasi `std::multiset` sekaligus menggunakan konstruktor *range*:

```cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    int n = 5;
    std::vector<int> vec = {40, 10, 20, 10, 30};

    // Jauh lebih efisien dibanding memanggil insert() satu per satu dalam loop
    std::multiset<int> angka(vec.begin(), vec.end());

    std::cout << "Isi multiset:\n";
    for (int x : angka) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## Alasan Efisiensi Konstruksi dari *Vector*

Pendekatan pengisian melalui *range constructor* jauh lebih cepat dibandingkan memanggil fungsi `insert()` secara berulang karena memungkinkan pengoptimalan struktur internal wadah.

Ketika kita memasukkan elemen satu per satu ke dalam `std::multiset` yang kosong, setiap panggilan fungsi `insert()` memaksa *tree* untuk melakukan penelusuran dari akar (*root*) dan sering kali memicu penyeimbangan ulang (*rebalancing* dan rotasi *node*) pada *Red-Black Tree*. Akibatnya, alokasi memori dan penataan ulang terjadi secara terus-menerus pada setiap iterasi.

Sebaliknya, ketika kita menginisialisasi `std::multiset` langsung dari rentang *vector* (terutama jika elemen di dalam *vector* sudah diurutkan terlebih dahulu, atau diproses secara massal), pustaka standar dapat membangun struktur *tree* secara lebih langsung dengan meminimalkan operasi rotasi yang mahal. Pendekatan ini menghindari *overhead* struktural yang berlebihan, sehingga proses pengisian data dalam jumlah besar menjadi jauh lebih optimal.