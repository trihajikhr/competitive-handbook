---
obsidianUIMode: preview
note_type: latihan
latihan: Kumpulan Latihan Singkat
sumber:
  - Google
tags:
  - combinatorics
date_learned: 2025-08-12T01:58:00
---
---
# Soal Sederhana

## 1 | Pertukaran Siswa
Dari 7 siswa putra dan 5 siswa putri akan dipilih 6 siswa untuk dikirim ke Jepang dalam rangka pertukaran siswa. Tentukan berapa banyak pilihan kombinasi siswa yang dapat dipilih?

### Jawaban

Perhatikan bahwa dalam soal, tidak ada ketentuan minimal laki-laki atau perempuan yang harus ada dalam kelompok. Artinya, kita bisa menggunakan rumus:

$$\binom{putra + putri}{6}$$

Berikut kodenya:

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int r) -> long long {
   r = min(r, n - r);

   long long rest = 1;

   for (int i = 1; i <= r; i++) {
      rest *= (n - i + 1);
      rest /= i;
   }

   return rest;
}

auto main() -> int {
   int man, woman, tim;
   cin >> man >> woman >> tim;
   cout << nCr(man + woman, tim);
   return 0;
}
```

Masukan inputan berupa:

```
7 5 6
```

Maka jawabanya adalah $924$.

## 2 | Kepanitiaan

Suatu kepanitiaan terdiri atas 3 pria dan 2 wanita. Jika banyaknya siswa yang diusulkan untuk tergabung dalam panitia tersebut ada 7 pria dan 9 wanita. Maka, berapa banyak susunan panitia yang dapat dibentuk?  

### Jawaban

Disini, ada kepanitiaan yang harus terdiri dari 3 pria, dan 2 wanita, dan tersedia 7 pria dan 9 wanita. Ini artinya kita perlu mencari kombinasi dari masing-masing laki-laki dan perempuan yang bisa menjadi panitia. Rumus berikut bisa digunakan:

$$\binom{\text{panitia laki-laki}}{\text{jumlah laki-laki}} \times \binom{\text{panitia perempuan}}{\text{jumlah perempuan}}$$

Atau $C\binom{7}{3} \times C\binom{9}{2}$. Berikut adalah implementasinya:

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int r) -> long long {
   r = min(r, n - r);

   long long rest = 1;

   for (int i = 1; i <= r; i++) {
      rest *= (n - i + 1);
      rest /= i;
   }

   return rest;
}

auto main() -> int {
   int pan_laki, jml_laki, pan_perempuan, jml_perempuan;
   cin >> pan_laki >> jml_laki >> pan_perempuan >> jml_perempuan;

   cout << nCr(jml_laki, pan_laki) * nCr(jml_perempuan, pan_perempuan);
   return 0;
}
```

Jika kita memasukan inputan:

```
3 7 2 9
```

Maka hasilnya adalah $1260$ kemungkinan.

## 3 | Guru dan Siswa
Dalam kelas terdapat 25 siswa, berapa banyak cara guru dapat memilih 4 siswa untuk mewakili kelas dalam suatu acara?

Jawaban:

Kita cukup menggunakan rumus kombinasi dari $\binom{25}{4}$:

$$\binom{25}{4}=\frac{25!}{4!(25-4)!}$$

Atau, jika kita menggunakan efisiensi memory, mengantisipasi nilai overflow, kita bisa menggunakan cara ini:

$$
\binom{25}{4} = \frac{25}{1} \times \frac{24}{2} \times \frac{23}{3} \times \frac{22}{4}= 12650
$$

```cpp
#include <iostream>
using namespace std;

auto nCr(int n, int r) -> long long {
   r = min(r, n - r);

   long long rest = 1;

   for (int i = 1; i <= r; i++) {
      rest *= (n - i + 1);
      rest /= i;
   }

   return rest;
}

auto main() -> int {
   int siswa, pilih;
   cin >> siswa >> pilih;

   cout << nCr(siswa, pilih);
   return 0;
}
```

Masukan inputan berupa:

```
25 4
```

Maka hasilnya adalah benar $12650$ cara.

