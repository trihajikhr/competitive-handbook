---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1743A
judul_STRIKE: Password
teori_STRIKE: Mencari permutasi dan menghiraukan yang tidak penting
sumber:
  - codeforces
ada_tips?: true
date_learned: 2025-08-14T00:33:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1743A - Codeforces](https://codeforces.com/problemset/problem/1743/A)

```ad-tip
title:⚔️ Teori STRIKE
Mencari banyaknya cara menyusun password yang terdiri dari 4 slot, dengan hanya 2 digit saja. Disini kita belajar menggabungkan rumus kombinasi untuk mencari banyaknya kombinasi yang mungkin dari beberapa batasan yang diberikan! 

Dan juga kita belajar untuk berhati-hati terhadap soal yang mengecoh! (lihat webpage soal asli agar tahu apa maksudnya!)
```

- [ ] Pelajari teori dan penerapan Kombinasi!
- [ ] Pelajari teori dan penerapan Permutasi!

<br/>

---
# 1 | Password

Monocarp lupa kata sandi ponselnya. Kata sandi tersebut terdiri dari 4 digit angka dari $0$ hingga $9$ (perhatikan bahwa kata sandi bisa diawali digit $0$).

Monocarp ingat bahwa kata sandinya memiliki **tepat dua digit berbeda**, dan **masing-masing digit tersebut muncul tepat dua kali** dalam kata sandi. Monocarp juga ingat beberapa digit yang **pasti tidak digunakan** dalam kata sandi.

Tugasmu adalah menghitung banyaknya urutan 4 digit berbeda yang mungkin menjadi kata sandi Monocarp (artinya, urutan tersebut harus memenuhi semua batasan kata sandi yang diingat Monocarp).

#### Input:

* Baris pertama berisi satu bilangan bulat $t$ $(1 \le t \le 200)$ — jumlah *test case*.
* Baris pertama dari setiap *test case* berisi satu bilangan bulat $n$ $(1 \le n \le 8)$ — jumlah digit yang diingat Monocarp **tidak** digunakan dalam kata sandi.
* Baris kedua berisi $n$ bilangan bulat berbeda $a_1, a_2, \dots, a_n$ $(0 \le a_i \le 9)$ yang menunjukkan digit-digit yang tidak digunakan dalam kata sandi. Digit-digit $a_1, a_2, \dots, a_n$ diberikan dalam urutan menaik.

#### Output:
Untuk setiap *test case*, cetak satu bilangan bulat — banyaknya urutan 4 digit yang memenuhi semua batasan tersebut.


<br/>

---
# 2 | Sesi STRIKE ⚔️

Untuk menyusun sebuah password, umumnya kita menggunakan pendekatan permutasi, karena setiap urutan penting. Tapi, jika diperbolehkan mengulang angka dalam susunan passwordnya, maka jawaban dari banyaknya permutasi yang mungkin adalah banyaknya karakter yang diperbolehkan, dikalikan dengan nilai tersebut lagi sebanyak banyaknya slot.

Belajar lagi metode permutasi untuk lebih memahami banyak pembahasan seputar kombinatorika. Dan soal ini juga ternyata lebih condong ke arah kombinasi daripada permutasi. 


1. **Bedakan “memilih” dan “menyusun”**

   * Pilih elemen dengan kombinasi, lalu atur posisinya dengan permutasi multiset.
   * Menghindari hitung ganda atau terlewat syarat.
<br/>

1. **Gunakan Konsep Multiset untuk Frekuensi Tetap**

   * Contoh: “tepat dua digit berbeda, masing-masing muncul 2 kali” → langsung pakai $\frac{4!}{2!2!}$.
<br/>

1. **Sederhanakan Rumus Final**

   * Dari $\binom{10-n}{2} \cdot \binom{4}{2}$ → bentuk sederhana:
		$$
		\binom{10-n}{2} \times 6
		$$
     atau
		$$
		3 \cdot (10-n) \cdot (9-n)
		$$
	→ lebih cepat untuk perhitungan manual atau debugging.
<br/>

4. **Validasi dengan Edge Case**

   * $n = 0$: semua digit bisa dipakai.
   * $n = 8$: hanya tersisa 2 digit → tepat 1 kemungkinan urutan.
   * $n \ge 9$: tidak mungkin membuat password.

#tips-trick Mengetahui kapan suatu soal perlu menggunakan kombinasi, dan kapan menggunakan permutasi sangatlah penting! Baca dengan cermat soal yang diberikan!

<br/>

---


# 3 | Jawaban dan Editorial
## 3.1 | Analisis Official

Ada dua kemungkinan solusi untuk masalah ini.

**Solusi pertama** pada dasarnya adalah *brute force*. Setiap kata sandi dapat direpresentasikan sebagai bilangan bulat dari $0$ hingga $9999$. Jika angkanya berada pada rentang $1000$ hingga $9999$, maka itu sudah merupakan kata sandi dengan panjang 4 digit.

Jika kurang dari 1000, tambahkan nol di depannya sampai panjangnya menjadi 4 digit.

Setelah itu, periksa apakah kata sandi tersebut **valid**:

1. Periksa apakah kata sandi terdiri dari **tepat dua digit berbeda** — buat *set* dari semua karakternya (`set<char>`pada C++, misalnya) dan periksa ukurannya.
2. Periksa apakah digit pertama dari kata sandi muncul **tepat dua kali**. Jika benar, maka digit lainnya juga muncul tepat dua kali.
3. Terakhir, pastikan bahwa kedua digit tersebut **tidak termasuk** dalam daftar digit yang dilarang.

**Solusi kedua** berbasis **kombinatorika**:

1. Pilih dua digit yang akan digunakan dalam kata sandi: $\binom{10 - n}{2}$
   Karena $n$ digit dilarang, berarti ada $10 - n$ digit yang diperbolehkan.
2. Pilih posisi untuk digit pertama: $\binom{4}{2}$
3. Jawaban akhir adalah hasil perkalian dari kedua nilai tersebut.

Berikut salah satu contoh implementasinya:

```cpp
#include <bits/stdc++.h>

using namespace std;

int n;

inline void read() {	
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
        cin >> x;
}

inline int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

inline int c(int n, int k) {
    return fac(n) / fac(k) / fac(n - k);
}

inline void solve() {
    cout << c(10 - n, 2) * c(4, 2) << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--){
        read();
        solve();
    }
}
```

## 3.2 | Analisis Pribadi

Dari editorial resmi, dibocorkan bahwa kita bisa menggunakan 2 metode penyelesaian, namun mungkin jauh lebih baik untuk menggunakan metode penyelesaian yang lebih terstruktur, yaitu menggunakan pendekatan kombinatorika.

```ad-hint
Monocarp lupa kata sandi ponselnya. Kata sandi tersebut terdiri dari 4 digit angka dari $0$ hingga $9$ (perhatikan bahwa kata sandi bisa diawali digit $0$).
```

Jika semisal kita ingin mengetahui banyaknya kombinasi yang mungkin dari sandi yang bisa dibuat dengan 4 slot dan angka antara 0-9, maka jawabanya adalah $10 \times 10 \times 10 \times 10=10000$. Ini adalah metode permutasi dengan pengulangan, dimana setiap urutan penting dan karakter yang sama boleh muncul lagi.

Namun, dengan beberapa batasan, sehingga kita perlu melakukan sedikit penyesuaian.

Diberikan informasi bahwa kita dilarang menggunakan beberapa digit untuk membentuk sandi, sebanyak $n$. 

```ad-hint
Monocarp ingat bahwa kata sandinya memiliki **tepat dua digit berbeda**, dan **masing-masing digit tersebut muncul tepat dua kali** dalam kata sandi. Monocarp juga ingat beberapa digit yang **pasti tidak digunakan** dalam kata sandi.
```

Akan ada sebanyak $n$ digit yang dilarang digunakan dalam pembuatan sandi, yang artinya, dari $10$ digit yang tersedia, sekarang hanya tersedia $10-n$ digit yang diperbolehkan.

Nahh, banyaknya digit yang tersedia untuk digunakan sekarang berkurang. Tapi ingat lagi, bahwa ada 2 digit angka yang pasti digunakan dalam sandi tersebut, dan kemunculanya adalah sebanyak 2 kali, atau muncul sekaligus. Sehingga, sandi yang mungkin itu mungkin seperti ini:

0099, 8778, 4554, 1313, 2112, 0044, 5566, dan seterusnya, hanya 2 digit berbeda yang muncul dua kali. 

Itu artinya, kita perlu menghitung, berapa banyak kombinasi 2 angka berbeda dari digit yang tersisa. Didapat rumus yaitu $C(10-n, 2)$.

Nah, setelah mengetahui banyaknya kombinasi yang mungkin dari 2 digit tersebut, kita juga perlu mencari tahu banyaknya kombinasi menyusun 2 digit tersebut pada 4 slot password yang tersedia, sehingga diambil rumus $C(4, 2)$.

Sehingga, rumus final sekaligus jawaban dari soal ini, adalah berikut:

$$\binom{10-n}{2} \times \binom{4}{2}$$

Jadi, ini implementasinya:

```cpp
/*
Author  : Riveris
Date    : 2025-08-11 20:13
Problem : Codeforces 1743A | Password
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto comb(int n, int k) -> long long {
   k = min(k, n - k);
   long long rest = 1;

   for (int i = 1; i <= k; i++) {
      rest = rest * (n - i + 1);
      rest /= i;
   }

   return rest;
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      for (int i = 0; i < n; i++) {
         int x;
         cin >> x;
      }

      cout << comb(10 - n, 2) * comb(4, 2) << '\n';
   }
   return 0;
}
```

> Algoritma menghitung kombinasi ini menggunakan metode yang ditingkatkan, pelajari ini di  algoritma mencari kombinasi, [[Koefisien Binomial]] untuk memahami ini!
