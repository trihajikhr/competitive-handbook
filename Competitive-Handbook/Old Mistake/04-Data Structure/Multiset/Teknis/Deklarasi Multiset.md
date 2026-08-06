---
obsidianUIMode: preview
note_type: book theory
judul_materi: Deklarasi Multiset
sumber:
  - myself
date_learned: 2026-07-27T21:36:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Deklarasi Multiset

*Multiset* adalah salah satu wadah asosiatif dalam *Standard Template Library* C++ yang menyimpan elemen secara terurut dan mengizinkan adanya elemen duplikat. Di bawah ini adalah berbagai cara untuk mendeklarasikan *multiset* beserta contoh implementasinya dalam bahasa C++.

## Deklarasi *Multiset* Kosong secara Standar

Cara paling dasar adalah mendeklarasikan *multiset* dengan menentukan tipe data elemennya. Secara *default*, elemen akan diurutkan secara *ascending* menggunakan operator pengurutan kurang dari.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> angka;
    return 0;
}
```

## Deklarasi dengan *Custom Comparator* (*Descending*)

Jika urutan elemen ingin dibalik menjadi *descending*, kita dapat menyertakan fungsi pembanding seperti `std::greater<T>` pada saat deklarasi tipe data.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int, std::greater<int>> angka_turun;
    return 0;
}

```

## Inisialisasi Langsung dengan Daftar Nilai (*Initializer List*)

Kita bisa langsung memasukkan beberapa nilai awal ke dalam *multiset* saat deklarasi menggunakan kurung kurawal.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> buah = {5, 2, 8, 2, 1, 5};
    return 0;
}

```

## Deklarasi Melalui *Range* dari Wadah Lain

Sebuah *multiset* dapat diinisialisasi dengan menyalin elemen dari wadah lain yang memiliki tipe data kompatibel, misalnya menggunakan rentang iterator dari sebuah *vector*.

```cpp
#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> v = {10, 20, 10, 30, 20};
    std::multiset<int> salinan(v.begin(), v.end());
    return 0;
}

```

## *Copy Constructor* (Menyalin *Multiset* Lain)

Kita juga dapat membuat *multiset* baru dengan menyalin seluruh isi dari *multiset* yang sudah ada sebelumnya.

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> sumber = {3, 1, 4, 1, 5};
    std::multiset<int> duplikat(sumber);
    return 0;
}

```

## Deklarasi Menggunakan *Custom Comparator* Berbasis *Struct*

Ketika kita ingin menyimpan objek kustom atau mengatur logika pengurutan yang lebih spesifik daripada sekadar naik atau turun, kita dapat menggunakan *struct* yang mengimplementasikan *operator()* (sering disebut sebagai *functor*).

```cpp
#include <iostream>
#include <set>

struct CustomCompare {
    bool operator()(const int &a, const int &b) const {
        // Aturan khusus: urutkan berdasarkan nilai sisa bagi 3 terlebih dahulu
        if (a % 3 != b % 3) {
            return a % 3 < b % 3;
        }
        return a < b;
    }
};

int main() {
    std::multiset<int, CustomCompare> angka_khusus = {7, 2, 5, 4, 10};
    return 0;
}
```

## Deklarasi Menggunakan *Lambda Expression* (C++20 ke atas)

Mulai standar C++20, kita dapat menggunakan *lambda expression* langsung sebagai tipe *comparator* pada parameter *template* wadah asosiatif. Namun, karena *type* dari *lambda* bersifat unik dan anonim, kita perlu memanfaatkan `std::decltype` atau melewatkannya melalui *constructor* dengan argumen fungsi (*constructor argument*).

```cpp
#include <iostream>
#include <set>

int main() {
    auto cmp = [](int a, int b) {
        return a > b; // Logika *descending* kustom
    };
    
    std::multiset<int, decltype(cmp)> angka_lambda(cmp);
    angka_lambda.insert(10);
    angka_lambda.insert(20);
    
    return 0;
}
```