---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 
judul_STRIKE: 
teori_STRIKE: 
sumber: 
ada_tips?: 
date_learned: 
tags:
  - STRIKE
---
Sumber:

```ad-tip
title:⚔️ Teori STRIKE
```

<br/>

---
# 1 | Judul

<br/>

---
# 2 | Sesi STRIKE ⚔️

#tips-trick 
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

## 3.2 | Analisis Pribadi

Sebelumnya aku sudah mencoba untuk mengamati jawaban dari user lain, dan berikut adalah kode yang aku buat:

```cpp
/*
Author  : Riveris
Date    : 2025-08-30 16:53
Problem : TLX-Toki | I - Diskon 50%, S&K Berlaku - Gemastik 2024 Penyisihan
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace {
inline void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
}  // namespace

using LL = long long;

auto main() -> int {
    fastio();
    int n = 0;
    int q = 0;
    LL total = 0;
    cin >> n >> q;
    vector<int> book(n);
    vector<int> day(q);
    for (auto& x : book) {
        cin >> x;
        total += x;
        x /= 2;
    }

    ranges::sort(book, greater<>());
    vector<LL> diskon(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j += i + 1) {
            diskon[i] += book[j];
        }
    }

    for (auto& i : day) {
        cin >> i;
        if (i > n) {
            cout << total << '\n';
        } else {
            cout << total - diskon[i - 1] << '\n';
        }
    }
    return 0;
}
```

Oke, baiklah, mari kita bedah kenapa kode ini berhasil.

Pertama, ketahui dulu bahwa banyaknya buku yang bisa Gema beli, adalah $A_j$, dimana nilai maksimalnya adalah hingga $10^9$, cukup besar, namun tidak cukup besar untuk membuat kita harus menggunakan tipe data `long long`. Jadi, buat 2 vector untuk menampung banyaknya buku, dan banyaknya hari yang tersedia dengan cukup `int` saja.

Lalu, perhatikan kode ini:

```cpp
for (auto& x : book) {
	cin >> x;
	total += x;
	x /= 2;
}
```

Setiap harga buku yang kita simpan, adalah setengah nilai. Kita justru langsung menjumlahkan harga dari setiap buku yang ada, dengan menampungnya dengan tipe data `long long`, yaitu `total`. 

AAAA

Setelah buku-buku tersebut diterima, untuk mempermudahkan pemilihan buku mana yang harus diambil, kita bisa mengurutkanya, atau sorting, dengan urutan descending, atau dari besar ke urutan kecil. 

```cpp
ranges::sort(book, greater<>());
```

Setelah itu, buat vector lagi, namun dengan tipe data `long long`. Ini karena akan digunakan untuk menampung ukuran yang sangat besar disini:

```cpp
vector<LL> diskon(n, 0);
```

Nah, sekarang perhatikan kode ini:

```cpp
for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j += i + 1) {
		diskon[i] += book[j];
	}
}
```

Apa maksud dari kode ini?

Kode ini akan melakukan perulangan sebanyak $n$ kali, atau banyaknya buku. Lalu didalamnya juga ada perulangan lagi, namun dengan pengkondisian yang lebih berbeda:

```cpp
for (int j = i; j < n; j += i + 1) {}
```

Nilai $j$ dideklarasikan dengan $i$, atau perulangan diatasnya. Dan juga incremenya 


## 3.3 | Analisis Jawaban User Lain